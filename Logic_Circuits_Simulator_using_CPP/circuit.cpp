#include "Node.h"
#include "Gate.h"
#include "GateAND.h"
#include "GateNOT.h"
#include "GateOR.h"
#include "Circuit.h"
#include <fstream>
#include <sstream>

using namespace std;

void Circuit::show_gates()
{
	for (unsigned int i=0; i < gates.size(); i++)
	{
		cout << typeid(*gates[i]).name() << " << ";
		for (unsigned int j=0; j < gates[i]->inputs.size(); j++)
		{
			gates[i]->inputs[j].show_value();
		}
		cout << " >> ";
		gates[i]->output.show_value();
		cout << endl;
	}
	cout << endl;
}

void Circuit::inputs_to_gates()
{
    //cout<<"Initial input value from txt file :"<<endl;
	for (unsigned int i = 0; i<inputs.size(); i++)
	{
		for(vector<Gate*>::iterator iter=gates.begin(); iter< gates.end(); ++iter)
		{
			Gate* G= *iter;
			for(unsigned int j = 0; j<(*G).inputs.size();j++)
			{
				if((*G).inputs[j].name == inputs[i].name)
				{
					(*G).inputs[j].value = inputs[i].value;
					(*G).inputs[j].already_computed = true;
				}
			}
		}
	}
}

void Circuit::gates_to_outputs()
{
    cout<<"OUTPUTS :"<<endl;
	for(vector<Gate*>::iterator iter=gates.begin(); iter< gates.end(); ++iter)
			{
				Gate* G= *iter;
				for (unsigned int i=0;i<outputs.size();i++)
				{
					if (outputs[i].name==(*G).output.name)
					{
						outputs[i].set_value((*G).output.value);
						cout<<outputs[i].name<<"=";
						cout<<outputs[i].value<< outputs[i].already_computed << endl;
						
						//outputs[i].already_computed = true;
					}
				}
			}
}

void Circuit::internal_outputs_to_inputs()
{
    for(Gate* currentGate : gates)  //check all gates output
    {
        if(currentGate->output.already_computed == true)
        {
            for (Gate* gateToUpdate : gates)
            {
                for(int i = 0; i<gateToUpdate->inputs.size(); i++)
                {
                    if(gateToUpdate->inputs[i].name == currentGate->output.name)
                    {
                        gateToUpdate->inputs[i].set_value(currentGate->output.value);
						
                    }
                }
            }
        }
    }
}

bool Circuit::are_all_outputs_computed()
{
    bool computed = true;
    for (int i =0; i<outputs.size(); i++)
    {
        if (outputs[i].already_computed == false)
            computed = false;
    }
    /*
    for (Node currentNode: outputs)
    {
        //cout<<"node : "<<currentNode.name<<" is computed = "<<currentNode.already_computed<<endl;
        if (currentNode.already_computed == false)
        {
            computed = false;
        }
    }
    */
    //cout<<"All outputs are computed!"<<computed<<endl;
    return computed;
}

void Circuit::reset()
{
	for (Gate *i : gates)
	{
		i->output.already_computed = false;
		for (Node& j : i->inputs)
		{
			j.already_computed = false;
		}
	}
}


void Circuit::compute()
{
	cout << endl << "Start to compute " << endl;
	inputs_to_gates();
	int calc_cycle(1);
	do
	{
		// Calculating the circuit
		cout << endl << " Round number " << calc_cycle << endl;
		for(Gate *i : gates)
		{
			i->calc_output();
		}

		internal_outputs_to_inputs();
		cout << endl << " Round number " << calc_cycle << " " << !are_all_outputs_computed() <<endl;
		calc_cycle += 1;
		show_gates();
	}
	while(!are_all_outputs_computed() && calc_cycle < 5);

	gates_to_outputs();
}



void Circuit::load_nodes_from_file()
{
	cout << "------ Generating Circuit nodes from Description file ------" << endl;
	vector<string> line_type = {"INPUT", "OUTPUT", "AND", "OR", "NOT"};
	string line;
	ifstream CircuitFile ("circuit.txt");
	while (getline(CircuitFile, line))
	{
		vector<string> line_vector(0);
		stringstream ss(line);
		string word;
		while (getline(ss, word, ' '))
		{
			line_vector.push_back(word); // each line is converted to a vector of word (string)
		}

			if ( line_vector[0] == "INPUT")
			{
				cout << "   > Constructing Inputs Nodes..." << endl;
				for(unsigned i=1; i < line_vector.size(); i++)
					{
						inputs.push_back(Node (line_vector[i]));
					}
			}
			else if ( line_vector[0] == "OUTPUT")
			{
				cout << "   > Constructing Outputs Nodes..." << endl;
				for(unsigned i=1; i < line_vector.size(); i++)
					{
						outputs.push_back(Node (line_vector[i]));
					}
                cout<<"End of output nodes creation"<<endl<<endl;
			}
			else    //create node if part of a gate and not already created
			{
			    for (int i = 1; i<line_vector.size(); i++)
                {
                    bool create = true;
                    for (Node currentNode: inputs)
                    {
                        if (currentNode.name == line_vector[i])
                        {
                            create = false;
                            break;
                        }
                    }
                    for (Node currentNode: outputs)
                    {
                        if (currentNode.name == line_vector[i])
                        {
                            create = false;
                            break;
                        }
                    }
                    for (Node currentNode: middle)
                    {
                        if (currentNode.name == line_vector[i])
                        {
                            create = false;
                            break;
                        }
                    }
                    if(create == true)
                    {
                        middle.push_back(Node (line_vector[i]));
                    }

                }
			}
	}
	CircuitFile.close();
	cout<<endl<<"Created nodes are:"<<endl;
	for (Node i: inputs)
    {
        cout<<i.name<<endl;
    }
    for (Node i: outputs)
    {
        cout<<i.name<<endl;
    }
    for (Node i: middle)
    {
        cout<<i.name<<endl;
    }
}

void Circuit::load_gates_from_file()
{
	cout << "------ Generating Circuit from Description file ------" << endl;
	vector<string> line_type = {"INPUT", "OUTPUT", "AND", "OR", "NOT"};
	string line;
	ifstream CircuitFile ("circuit.txt");
	while (getline(CircuitFile, line))
	{
		vector<string> line_vector(0);
		stringstream ss(line);
		string word;
		while (getline(ss, word, ' '))
		{
			line_vector.push_back(word); // each line is converted to a vector of word (string)
		}
		vector <Node*> tempVect;
		if((line_vector[0]=="AND")||(line_vector[0]=="OR")||(line_vector[0]=="NOT"))
        {
            for (int inputNumber = 1; inputNumber<line_vector.size(); inputNumber++)
            {
                int index = 0;
                for (int i = 0; i<inputs.size(); i++)
                {
                    if (inputs[i].name == line_vector[inputNumber])
                    {
                        tempVect.push_back(&(inputs[i]));
                        break;
                    }
                }
                index = 0;
                for (int i = 0; i<outputs.size(); i++)
                {
                    if (outputs[i].name == line_vector[inputNumber])
                    {
                        tempVect.push_back(&(outputs[i]));
                        break;
                    }
                }
                index = 0;
                for (int i = 0; i<middle.size(); i++)
                {
                    if (middle[i].name == line_vector[inputNumber])
                    {
                        tempVect.push_back(&(middle[i]));
                        break;
                    }
                }
            }
            //create the gate
            if ( line_vector[0] == "AND")
            {
                gates.push_back(new GateAND (*(tempVect[1]), *(tempVect[2]), *(tempVect[0])));
            }
            else if ( line_vector[0] == "OR")
            {
                gates.push_back(new GateOR (*(tempVect[1]), *(tempVect[2]), *(tempVect[0])));
            }
            else
            {
                gates.push_back(new GateNOT (*(tempVect[1]), *(tempVect[0])));
            }
        }
	}
}

void Circuit::load_inputs_from_file()
{
	cout << " Loading Simulation Inputs from File " << endl;
	string line;
	ifstream InputFile ("inputs.txt");
	getline(InputFile, line);
	//int simulation_round = int(line);
	getline(InputFile, line);
	vector<string> names (0);
	int nb_inputs = int(line.size());
	for (int i=1; i <= nb_inputs; i++)
	{
		names.push_back("I"+char(i));
	}
	for (int i=0; i < nb_inputs; i++)
	{
		if (line[i] == '0')
		{
			inputs[i].set_value(false);
		}
		else if (line[i] == '1')
		{
			inputs[i].set_value(true);
		}
	}
	cout << "   > Vector size = " << nb_inputs << endl << "   > Primary Inputs assigned to : " << endl;
	for (Node& i : inputs)
	{
		cout << "      ";
		i.show_value();
		cout << endl;
	}
}

void Circuit::write_outputs_to_file()
{
	cout << endl << " Writing outputs.txt " << endl;
	ofstream OutputFile ("output.txt");
	vector<bool> PO(0);
	for (const Node& i : outputs)
	{
		OutputFile << i.value;
	}
}

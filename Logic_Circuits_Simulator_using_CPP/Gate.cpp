#include "Node.h"
#include "Gate.h"

using namespace std;


void Gate::show()
{
	for (unsigned int i = 0; i<inputs.size(); i++)
	{
		inputs[i].show_value();
	}
	cout << " | ";
	output.show_value();
	cout << endl;
}

int Gate::calc_output()
{
    bool Comp = true;
    for (Node i: inputs)
    {
        if (i.already_computed == false)
        {
            Comp = false;
            break;
        }
    }
    if (Comp)
    {
        calc_output_self();
        output.already_computed = true;
    }
return -1;
}

void Gate::configure_for_two_inputs(const Node& input1, const Node& input2, const Node& out)
{
	inputs.push_back(input1);
	inputs.push_back(input2);
	output=out;
}

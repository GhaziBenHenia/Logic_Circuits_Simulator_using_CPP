#include "Node.h"
#include "Gate.h"
#include "GateAND.h"
#include "GateOR.h"
#include "GateNOT.h"
#include "Circuit.h"

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


int main()
{
    /*
	Node N1("N1",true), N2("N2",true), N3("N3");
	N1.show_value();
	N2.show_value();
	N3.show_value();
	N3.set_value(true);
	N3.show_value();
	*/

	/*Gate G;
	G.inputs.push_back(N1);
	G.inputs.push_back(N2);
	G.output=N3;
	G.calcul_output();
	G.show();*/

	/*GateAND G1 ( Node ("I1",false ) , Node ("I2",false ) , Node ("O") ) ;
	G1.calcul_output();
	G1.show();
	GateAND G2 ( Node ("I1",false ) , Node ("I2",true ) , Node ("O") ) ;
	G2.calcul_output();
	G2.show();
	GateAND G3 ( Node ("I1",true ) , Node ("I2",false ) , Node ("O") ) ;
	G3.calcul_output();
	G3.show();
	GateAND G4 ( Node ("I1",true ) , Node ("I2",true ) , Node ("O") ) ;
	G4.calcul_output();
	G4.show();
	G1.truth_table();*/

	/*GateOR G5 ( Node ("I1",false ) , Node ("I2",false ) , Node ("O") ) ;
	G5.calcul_output();
	G5.show();
	GateOR G6 ( Node ("I1",false ) , Node ("I2",true ) , Node ("O") ) ;
	G6.calcul_output();
	G6.show();
	GateOR G7 ( Node ("I1",true ) , Node ("I2",false ) , Node ("O") ) ;
	G7.calcul_output();
	G7.show();
	GateOR G8 ( Node ("I1",true ) , Node ("I2",true ) , Node ("O") ) ;
	G8.calcul_output();
	G8.show();
	G5.truth_table();*/

	/*GateNOT G9 ( Node ("I",true ) , Node ("O") ) ;
	G9.calcul_output();
	G9.show();
	GateNOT G10 ( Node ("I",false ) , Node ("O") ) ;
	G10.calcul_output();
	G10.show();
	G9.truth_table();*/

	/*
	Circuit Circ ;
	Circ.gates.push_back(new GateAND(Node("I1"), Node("I2"), Node("A"))) ;
	Circ.gates.push_back(new GateOR(Node("I3"), Node("I4"), Node("B"))) ;
	Circ.gates.push_back(new GateAND(Node("B"), Node("I5"), Node("C"))) ;
	Circ.gates.push_back(new GateOR(Node("A"), Node("C"), Node("O1"))) ;
	Circ.gates.push_back(new GateOR(Node ("C"), Node("I6"), Node("O3"))) ;
	Circ.gates.push_back(new GateNOT( Node("C"), Node("O2"))) ;

	//Circ.reset();
	//Circ.show_gates();

	Circ.inputs.push_back(Node("I1",false));
	Circ.inputs.push_back(Node("I2",true));
	Circ.inputs.push_back(Node("I3",false));
	Circ.inputs.push_back(Node("I4",false));
	Circ.inputs.push_back(Node("I5",true));
	Circ.inputs.push_back(Node("I6",true));

	Circ.outputs.push_back(Node("O1"));
	Circ.outputs.push_back(Node("O2"));
	Circ.outputs.push_back(Node ("O3"));
	*/

	Circuit Circ;

	Circ.load_nodes_from_file();
	Circ.load_gates_from_file();
	Circ.load_inputs_from_file();

	Circ.compute();

	Circ.write_outputs_to_file();


	return 0;
}

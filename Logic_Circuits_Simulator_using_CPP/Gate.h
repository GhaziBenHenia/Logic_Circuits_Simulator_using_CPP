#ifndef GATE_H_
#define GATE_H_

#include <iostream>
#include <vector>
#include "Node.h"



class Gate
{
public:	string name;
		vector<Node> inputs;
		Node output;

		void show();
		void configure_for_two_inputs(const Node& input1, const Node& input2, const Node& out);
		virtual int calc_output();
		virtual void calc_output_self()=0;
};

#endif /* GATE_H_ */

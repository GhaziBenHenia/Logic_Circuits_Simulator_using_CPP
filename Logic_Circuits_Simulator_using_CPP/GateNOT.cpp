#include "Node.h"
#include "Gate.h"
#include "GateNOT.h"

using namespace std;

GateNOT::GateNOT(const Node& input1 , const Node& out)
{
	inputs.push_back(input1);
	output=out;
}


void GateNOT::calc_output_self()
{
    output.value = not(inputs[0].value);
}

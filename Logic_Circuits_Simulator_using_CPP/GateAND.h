#ifndef GATEAND_H_
#define GATEAND_H_

#include "Gate.h"
#include "Node.h"


class GateAND: public Gate
{
	public: 
	GateAND(const Node& input1 , const Node& input2 , const Node& out);
	virtual void calc_output_self();
};



#endif /* GATEAND_H_ */


#ifndef GATENOT_H_
#define GATENOT_H_

#include "Gate.h"
#include "Node.h"

class GateNOT: public Gate
{
	public: 
	GateNOT(const Node& input1 , const Node& out);
	virtual void calc_output_self();
};



#endif /* GATENOT_H_ */


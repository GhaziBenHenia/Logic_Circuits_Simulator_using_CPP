#ifndef GATEOR_H_
#define GATEOR_H_

#include "Gate.h"
#include "Node.h"

class GateOR: public Gate
{
	public:
	    GateOR(const Node& input1 , const Node& input2 , const Node& out);
        //void truth_table();
        virtual void calc_output_self();
};



#endif /* GATEOR_H_ */

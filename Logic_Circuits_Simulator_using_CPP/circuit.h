#ifndef CIRCUIT_H_
#define CIRCUIT_H_


#include "Node.h"
#include "Gate.h"

class Circuit
{
public :	vector < Node > inputs ;
            vector < Node > middle ;
			vector < Node > outputs ;
			vector < Gate * > gates ;

			void show_gates () ;
			void inputs_to_gates () ;
			void gates_to_outputs () ;
			void internal_outputs_to_inputs () ;
			bool are_all_outputs_computed () ;
			void reset () ;
			void compute () ;

			void load_nodes_from_file();
            void load_gates_from_file();
            void load_inputs_from_file();
            void write_outputs_to_file();
};

#endif /* CIRCUIT_H_ */

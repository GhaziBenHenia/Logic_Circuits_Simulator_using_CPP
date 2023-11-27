#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class Node
{
public:

        string name;
		bool value;
		bool already_computed;

		Node();
		Node(string inName);
		Node(string inName, bool inValue);
		void set_value(bool inValue);
		void show_value();
};


#endif /* NODE_H_ */

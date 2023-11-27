#include "Node.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

Node::Node(){already_computed=false;};

Node::Node(string inName)
{
	name=inName;
	value=false;
	already_computed=false;
}

Node::Node(string inName, bool inValue)
{
	name=inName;
	value=inValue;
	already_computed=true;
}

void Node::set_value(bool inValue)
{
	value=inValue;
	already_computed=true;
}

void Node::show_value()
{
	cout<<name <<":";
	if (already_computed==false)
	{
		cout << "?";
	} else if (already_computed==true)
	{
		cout << value;
	}
	cout<<" ";
}

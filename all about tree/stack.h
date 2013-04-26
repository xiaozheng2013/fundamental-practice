#include "node.h"
#include<vector>
using namespace std;

class Stack{
public:
	int size;
	vector<node> items;
	Stack()
	{ size = 0; }
	
	int isEmpty()
	{ 
		if(size == 0) return 1;
		else return 0;
	}
	void push(node i)
	{
		size++;
		items.push_back(i);
	}
	void pop();

	node top()
	{
		if(size == 0) {cout<<"empty stack"<<endl;}
		else return items[size - 1];
		return NULL; 
	}
};


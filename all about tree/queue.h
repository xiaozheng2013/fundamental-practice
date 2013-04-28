#include "node.h"
#include<vector>
using namespace std;

class Queue{
public:
	int size;
	vector<node> items;
	Queue()
	{ size = 0; }
	
	int isEmpty()
	{
		return (size == 0);
	}
	void enQueue(node i)
	{
		size++;
		items.push_back(i);
	}
	void deQueue();

	node top()
	{
		if(size == 0) {cout<<"empty queue"<<endl;}
		else return items[0];
		return NULL; 
	}
		
};		

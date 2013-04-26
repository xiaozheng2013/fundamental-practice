#include "node.h"
class tree{
public:
	node *root;	
	int size;
	
	tree(){ size = 0; root = NULL; }
	void add(int a);
	void display(int i);
};



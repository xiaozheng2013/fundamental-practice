/*
this is a series of practice code, to help me be familiar with tree data stucture and ergodic algorithm
BST
start: 13:13, 2013/4/24

several mistakes: (1) forget to code default constructor in line 29
				(2) forget to add size by one after adding a new node
*/

#include "tree.h"

int main()
{
	tree a; 
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	a.display(0);
	return 0;

}

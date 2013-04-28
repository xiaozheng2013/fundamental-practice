/*
this is a series of practice code, to help me be familiar with tree data stucture and ergodic algorithm
BST
start: 13:13, 2013/4/24

several mistakes: (1) forget to code default constructor in line 29
				(2) forget to add size by one after adding a new node
*/

#include "tree.h"
#include<iostream>
using namespace std;
int main()
{
	tree a; 
	a.add(4);
	a.add(2);
	a.add(5);
	a.add(1);
	a.add(3);
	a.add(6);
	a.add(7);
	cout<<"pre-order ergodic: ";
	a.display(0);
	cout<<endl;
	cout<<"Depth-first ergodic: ";
	a.display(1);
	cout<<"Breadth-first ergodic: ";
	a.display(2);
	return 0;

}

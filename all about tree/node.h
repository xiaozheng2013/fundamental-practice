/*
this is a series of practice code, to help me be familiar with tree data stucture and ergodic algorithm
BST
start: 13:13, 2013/4/24

several mistakes: (1) forget to code default constructor in line 29
				(2) forget to add size by one after adding a new node
*/
#ifndef NODE_H
#define NODE_H
 
#include<iostream>
class node{
public:
	int val;
	node* par;
	node* lch;
	node* rch;
	node(int a)
	{ val =a; par = lch = rch = NULL; }

	void display();
	void dfs();
	void bfs();
};

#endif

/*
this is a series of practice code, to help me be familiar with tree data stucture and ergodic algorithm
BST
start: 13:13, 2013/4/24

several mistakes: (1) forget to code default constructor in line 29
				(2) forget to add size by one after adding a new node
*/
#include "tree.h"
void tree::display(int i)
{
	if(size != 0)
	{
		if(i == 0)
		root->display();
		if(i == 1)
		root->dfs();
	}
}

void tree::add(int a)
{
	if(size == 0)  { size++; root = new node(a);}
	else{
		node *tmp,*tmp1;
		tmp = tmp1 = root;
		while(tmp1 != NULL)
		{
			if(a<tmp1->val)
			{
				tmp = tmp1;
				tmp1 = tmp1->lch;
			}
			else 
			{
				tmp = tmp1;
				tmp1 = tmp1->rch;
			}
		}
		node *nnode = new node(a);
		nnode->par = tmp;	
		if(a<tmp->val) 
		{
			tmp->lch = nnode;
		}
		else tmp->rch = nnode;
		size++;
	}
}


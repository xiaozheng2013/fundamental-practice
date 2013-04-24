/*
this is a series of practice code, to help me be familiar with tree data stucture and ergodic algorithm
BST
start: 13:13, 2013/4/24

several mistakes: (1) forget to code default constructor in line 29
				(2) forget to add size by one after adding a new node
*/
#include<iostream>
using namespace std;

class node{
public:
	int val;
	node* par;
	node* lch;
	node* rch;
	node(int a)
	{ val =a; par = lch = rch = NULL; }

	void display();
};

class tree{
public:
	node *root;	
	int size;
	
	tree(){ size = 0; root = NULL; }
	void add(int a);
	void display();
};

void node::display()
{
	cout<<val<<" ";
	if(lch != NULL) lch->display();
	if(rch != NULL) rch->display();
}

void tree::display()
{
	root->display();
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

int main()
{
	tree a; 
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	a.display();
	return 0;

}

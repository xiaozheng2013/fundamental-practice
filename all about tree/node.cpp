//#include "node.h"
#include "stack.h"
#include<iostream>
using namespace std;

void node::display()
{
	cout<<val<<" ";
	if(lch != NULL) lch->display();
	if(rch != NULL) rch->display();
}

int contain(vector<node> a, node *b)
{
	if(b == NULL) return 1; //stands for contained
	else
	{
		for(int i=0;i<a.size();i++)
			if(a[i].val == b->val)
				return 1;
		return 0; //not visited 
	}
}

void node::dfs()
{
	vector<node> visited;
	Stack visit;
	visit.push(*this);
	visited.push_back(*this);
	while(visit.isEmpty() != 1)
	{
		node tmp = visit.top();
		if(contain(visited,tmp.lch) == 0) //eg not visited
		{
			visited.push_back(*(tmp.lch));
			visit.push(*(tmp.lch));
		}
		else if(contain(visited,tmp.rch) == 0)
		{
			visited.push_back(*(tmp.rch));
			visit.push(*(tmp.rch));
		}
		else visit.pop();
	}
		cout<<"dfs result:"; 
	for(int i=0;i<visited.size();i++)
		cout<<visited[i].val<<" ";
	cout<<endl;
}


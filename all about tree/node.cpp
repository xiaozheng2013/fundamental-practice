#include "node.h"
using namespace std;

void node::display()
{
	cout<<val<<" ";
	if(lch != NULL) lch->display();
	if(rch != NULL) rch->display();
}

void node::dfs()
{

}


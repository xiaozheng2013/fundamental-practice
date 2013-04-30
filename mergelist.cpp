#include<iostream>
using namespace std;

class node{
public:
	int val;
	node* next;	
	void insert(node*& p2);	
	node(int a);
	node* find_place_for(node* n2);
	void display();
	

};

class list{
public:
	node *first;
	node *last;
	int length;
	list();
	void display();
	void add(node* n);
	
};

node* node::find_place_for(node* n2)
{
	node* temp = this;
	while(temp->next->val < n2->val && temp->next != 0)
	{ temp = temp->next;}
	return temp;

}

void node::display()
{
	cout<<val<<endl;
}

void list::add(node* n)
{
	if(length == 0) {first = last = n;}
	else {last->next = n; last = last->next;}
	length++;
	

}

void list::display()
{
	if(length == 0) cout<<"empty list"<<endl;
	else{
	
	node *temp = first;
	while(temp->next!=0) {
	   cout<<temp->val<<" ";
	   temp = temp->next;
	}
	
	cout<<temp->val;
	cout<<endl;
	}
	

}

node::node(int a)
{
	val = a;

}

list::list()
{
	length = 0;

}

void node::insert(node*& p2)
{
	p2->next = this->next;	
	this->next = p2;
	return;
	

}


void listmerge(list*& p1,list*& p2)
{
	list *temp;
	node *temp1;
	if(p1 == 0) {p1 = p2; return;}
	else if(p2 == 0) return;	

	else if(p1->first->val > p2->first->val) 
	{
	   temp = p1;
	   p1 = p2;
	   p2 = temp;
	}
	
	node *n1,*n2;
	n1 = p1->first; n2 = p2->first;
	while(n1->next != 0 && n2->next != 0)
	{
		node *t1 = n1->find_place_for(n2);
		node *t2 = n2; n2 = n2->next;
		t1->insert(t2); n1 = t2;
	}
	if(n1->next == 0) n1->next = n2;
	p1->length = p1->length + p2->length;
	return;	
	

}

int main()
{
  	list *p1,*p2;
	p1 = new list;
	p2 = new list;
	node *a[11];
	for(int i=0;i<11;i++)
	{
	   int k = 2*i;
	   k = k%11;
	   a[i] = new node(k);
	}
	
	p1->add(a[0]);
	p1->add(a[1]);
	p1->add(a[2]);
	p1->add(a[3]);
	p1->add(a[4]);
	p1->add(a[5]);
	p2->add(a[6]);
	p2->add(a[7]);
	p2->add(a[8]);
	p2->add(a[9]);
	p2->add(a[10]);
list *temp;
temp = p2;
p2 = p1;
p1 = temp;
p1->display();cout<<endl;
p2->display();
cout<<"p1.length = "<<p1->length<<endl;
	listmerge(p1,p2);
	p1->display();

cout<<"p1.length = "<<p1->length<<endl;





}






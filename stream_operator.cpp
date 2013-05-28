#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;

class state{
public:
	int A;
	int B;
	int C;
	int a;
	int b;
	int c;
	state(int i,int j, int k)
	{
		A = i; B = j; C = k;
		a = 0; b = 0; c = k;
	}
	
	friend ostream& operator<<(ostream& os, const state& t)
	{
		cout<<"the milk contained in each bucket is : "<<t.a
			<<" "<<t.b<<" "<<t.c<<" "<<endl;
	}
	
};

int main()
{
	int a= 1, b =2, c =3;
	state *init;
	init = new state(a,b,c);
	cout<<*init<<endl;

	return 0;
}


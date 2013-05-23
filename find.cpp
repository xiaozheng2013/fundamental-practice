#include<iostream>
#include<vector>

using namespace std;

int find(vector<int>& a, int i, int j, int val)
{
	if(i>j) return -1;
	else if(i == j) 
	{
		if(a[i] == val) return i;
		else return -1;
	}
	else
	{
		int k = (i+j)/2;
		if(a[k] == val) return k;
		else if(a[k] > val)
		{
			j = k-1;
			return find(a,i,j,val);
		}
		else if(a[k]<val)
		{	
			i = k+1;
			return find(a,i,j,val);
		}	

	}

}

int main()
{

	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	int m = find(a,0,3,4);
	cout<<m<<endl;
}


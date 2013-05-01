/* problem description:
   N*N matrix, find all possible routes connecting left-upper corner with
   right-down corner.

   Note: use '1' to indicate moving to the right, use '0' to indicate moving
  	 down;
*/
#include<iostream>
#include<vector>

using namespace std;
int N= 10;

class route{
public:
   int length;	
   vector<int> way;
   void extends(int i);
   void display();
};

class routes{
public: 
   int length;
   vector<route> collection;
   route& operator[](int i);
   void Double();
   void resize(int i);
   void display();
};

void route::extends(int i)
{
   if(i == 0 || i == 1)
   {
	length++;
	way.push_back(i);


   }
   else cout<<"error1"<<endl;

};

void route::display()
{
   for(int i=0;i<length;i++)
   {
	
	cout<<way[i];
	if(i != length - 1)
	   cout<<"->";
   }
   cout<<endl;

};

route& routes::operator[](int i)
{
   if(i>-1 && i<length)
   	return collection[i];
   else cout<<"error"<<endl;

};

void routes::Double()
{
   for(int i=0;i<length;i++)
   {
	route *temp = new route(collection[i]);
	collection.push_back(*temp);
   }

   length *= 2;
};

void routes::resize(int i)
{
   length = i;
   collection.resize(i);

};

void routes::display()
{
   for(int i=0;i<length;i++)
   {
	collection[i].display();
   }


};
 
void find_routes(int m, int n, routes A)
{
   cout<<"love, m= "<<m<<" n = "<<n<<endl;
   if(m == 0 && n == 0) return;
   else if(m == 0 && n != 0)
   {
	for(int i=0;i<A.length;i++)
	{
	   for(int j=0;j<n;j++)
	   	A[i].extends(0);
 	}

   }


   else if(m != 0 && n == 0)
   {
	for(int i=0;i<A.length;i++)
	{
	   for(int j=0;j<n;j++)
	   	A[i].extends(1);
 	}

   }

  
   else if( m > 0 && n> 0)
   {
	if(A.length != 0)
	{
	   A.Double();
	   for(int i=0;i<A.length/2;i++)
	   {
		A[i].extends(0);
		A[i+n/2].extends(1);
	   }

	}
	else if(A.length == 0)
	{
	   A.resize(2);
	   A[0].extends(0);
	   A[1].extends(1);		
	   cout<<"A.length = "<<A.length<<endl;
	   A.display();
	}

   }

}


int main()
{
   routes A;
   find_routes(N,N,A);
   A.display();
   return 0;


}









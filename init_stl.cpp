#include<iostream>
#include<iomanip>
#include<complex>
using namespace std;

void init(complex<double>* a, int b)
{
	for(int i=0;i<b;i++)
		a[i] = 0.1;
}

void init(float* a, int b)
{
	for(int i=0;i<b;i++)
		a[i] = 0.1;
}

void init(double* a, int b)
{
	for(int i=0;i<b;i++)
		a[i] = 0.1;
}

int main()
{
	int N = 5;
	complex<double> *a1;
	double *a2;
	float *a3;
	a1 = (complex<double>*)calloc(N,sizeof(complex<double>));
	a2 = (double*)calloc(N,sizeof(double));
	a3 = (float*)calloc(N,sizeof(float));
	for(int i=0;i<N;i++)
	{
//		cout<<a1<<" ";
//		cout<<a2<<" ";
//		cout<<a3<<" ";
	}

	init(a1,N);
	init(a2,N);
	init(a3,N);
	for(int i=0;i<N;i++)
	{
		cout<<a1[i]<<" ";
		cout<<a2[i]<<" ";
		cout<<a3[i]<<" ";
	}

	delete a1;
	delete a2;
	delete a3; 
}


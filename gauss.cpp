#include<iostream>
#include<fstream>
#include<iomanip>
#include<complex>
#include<fftw3.h>
#include<math.h>

#define pi 4.0*atan(1)
using namespace std;
complex<double> one(0,1);

double radius ( complex<double> c )
// Returns the radius of the complex number.
{
   double result,re,im;
   re = real(c);im=imag(c);
   result = re*re + im*im;
   return sqrt(result);
}

void complexBackSubstitution(complex<double> *U[],
                     complex<double> *b,
                     complex<double> *x,
                     int M)
{
  int j,k,n;
  complex<double> sum;


  for(j=M-1;j>=0;j--){
    sum = 0.0;
    for(k=j+1;k<M;k++){
      sum += U[j][k]*x[k];
      }
    x[j]=(b[j]-sum)/U[j][j];
    }

} 

void complexTriangulate(complex<double> *A[],
                complex<double> *b,
                complex<double> *C[],
                complex<double> *d,
                int M)
{
  complex<double> temprow[M];
  complex<double> potentialpivot,pivot,factor,tempd;
  int j,k,m,n,pivotrow;


  n = M;
  for(j=0;j<M;j++)
  {
      temprow[j] = 0.0;
      d[j] = b[j];
      for(m=0;m<M;m++)
          C[j][m] = A[j][m];
  }
 	for(j=0;j<M-1;j++){

    /* Find largest pivot */
    pivot = C[j][j];
    pivotrow = j;
    for(m=j+1;m<n;m++){
      potentialpivot = C[m][j];
      //      if(fabs(potentialpivot)>fabs(pivot)){
      double judge;
      judge = radius(potentialpivot) - radius(pivot);
      if( judge > 1e-10 ){
    pivot = potentialpivot;
    pivotrow = m;
    }
      }

    /* Interchange rows and RHS */
    for(m=0;m<n;m++){
      temprow[m] = C[j][m];
      C[j][m] = C[pivotrow][m];
      C[pivotrow][m] = temprow[m];
      }
 	tempd = d[j];
    d[j] = d[pivotrow];
    d[pivotrow] = tempd;

    /* Resume factorization */
    for(k=j+1;k<M;k++){
      factor = C[k][j]/C[j][j];
      for(m=j;m<n;m++)
      {

          C[k][m] = C[k][m] - factor * C[j][m];
      }
      d[k] = d[k] - factor * d[j];
      }
    }

} 

void complexGaussElimination(complex<double> *A[],
                     complex<double> *b,
                     complex<double> *x, int M)
{
  complex<double> *C[M];
  complex<double> d[M];

  for(int i=0;i<M;i++)
  {
    d[i] = 0.0;
    C[i] = (complex<double> *)calloc(M,sizeof(complex<double>));
    for(int j = 0;j<M;j++)
        C[i][j] = 0.0;
  }

  complexTriangulate(A,b,C,d,M);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<M;j++)
		cout<<"C[i][j] = "<<C[i][j]<<endl;
	}
	for(int i=0;i<M;i++)
		cout<<"d[i] = "<<d[i]<<endl;
  complexBackSubstitution(C,d,x,M);

}  

int main()
{
	complex<double> *A[3];
	for(int i=0;i<3;i++)
	{
		A[i] = (complex<double>*)calloc(3,sizeof(complex<double>));
		for(int j=0;j<3;j++)
		{
			A[i][j] = 0;
		}

	}
//	A[0][0] = A[1][1] = A[2][2] = 1;
	A[0][1] = A[1][2] = -3.74;
	A[2][0] = 2.16;
	complex<double> b[3],x[3];
	for(int i=0;i<3;i++)	b[i] = 0;
	b[0] = 1;

	complexGaussElimination(A,b,x,3);
	for(int i=0;i<3;i++)
		cout<<x[i]<<endl;
	return 0;
}


	
		

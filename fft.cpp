#include<iostream>
#include<fstream>
//#include<math.h>
//#include<valarray>
#include<complex>
#include<fftw3.h>

using namespace std;

int main()
{
	int N = 4;
	fftw_complex *f;
	fftw_complex *fhat;
	f = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*(N));
	fhat = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*(N));
	for(int i=0;i<N;i++)
	{
		f[i][0] = f[i][1] = 1;
	}


	fftw_plan p;
	p = fftw_plan_dft_1d(N,f,fhat,FFTW_FORWARD,FFTW_ESTIMATE);
	fftw_execute(p);
	
	fftw_destroy_plan(p);
	for(int i=0;i<N;i++)
	{
		cout<<fhat[i][0]<<" "<<fhat[i][1]<<endl;
	}
	return 0;
}


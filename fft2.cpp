#include<iostream>
#include<fstream>
//#include<math.h>
//#include<valarray>
#include<complex>
#include<fftw3.h>

using namespace std;

int main()
{
	int nx = 4;
	int ny = 2;
	fftw_complex *f;
	fftw_complex *fhat;
	f = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*(nx*ny));
	fhat = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*(nx*ny));
	for(int i=0;i<nx;i++)
		for(int j=0;j<ny;j++)
		{
			int k= i*ny + j;
			f[k][0] = 1;
			f[k][1] = 0;
		}

	fftw_plan p;
	p = fftw_plan_dft_2d(nx,ny,f,fhat,FFTW_FORWARD,FFTW_ESTIMATE);
	fftw_execute(p);
	
	fftw_destroy_plan(p);
	for(int i=0;i<nx;i++)
		for(int j=0;j<ny;j++)
		{
			int k= i*ny + j;
			cout<<fhat[k][0]<<" "<<fhat[k][1]<<endl;
		}
	return 0;
}


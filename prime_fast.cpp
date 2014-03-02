#include <iostream>
#include <math.h>
using namespace std;

int get_prime(int n)
{
    int *p_r = new int[n];
    int count = 1;
    p_r[0] = 2;
    p_r[1] = 3;

    for(int i=3; count!=n; i+=2)
    {
        int sqrt_i = sqrt(i);
        for(int j=1; sqrt_i>=p_r[j] && i%p_r[j]!=0; ++j);

        if(sqrt_i<p_r[j])
        {
            p_r[count++] = i;
        }
    }
    return p_r[count-1];
}

int main()
{
    cout<<get_prime(1000000)<<endl;
    return 0;
}



// find the first 1000 prime
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool isprime(int can, vector<int>& res) {
    for(int i=1;i<res.size();i++) {
        int tp = res[i];
        if(can % tp == 0) return false;
        if(can < tp*tp) break;

    }
    return true;

}

int main() {
    vector<int> res;
    int num = 0;
    res.push_back(2);
    int can = 3;
    while(num < 1000000 ) {
        if(isprime(can, res)) {
            res.push_back(can);
            num++;
//          cout<<num<<endl;
        }
        can += 2;


    }
    cout<<"sum = "<<sum<<endl;
    return 0;


}



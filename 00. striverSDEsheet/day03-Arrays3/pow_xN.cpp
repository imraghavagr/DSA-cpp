#include<iostream>
#include<vector>
using namespace std;

//brute force soln - O(n)
double myPow(double x, int n) {
    double ans = 1.0;
    //to handle overflow
    long long nn = n;
    if(nn<0){
        nn = -1*nn;
    }
    
    //multiply x by itself n no. of times.
    for(int i = 0; i<nn; i++){
        ans *= x;
    }
    if(n<0){
        return 1/ans;
    }
    return ans;
}
//optimal O(logn) time approach
double myPow2(double x, int n){
    double ans = 1.0;
    //to handle overflow when multiplying n by -1
    long long nn = n;
    if(nn<0){
        nn = -1*nn;
    }

    //now use binary exponentiation method
    while(nn>0){
        if(nn&1){
            //odd
            ans = ans*x;
            nn = nn-1;
        }
        else{
            //even
            x = x*x;
            nn = nn/2;
        }
    }
    if(n<0) ans = (double)(1.0)/(double)(ans);
    return ans;
}
int main()
{
    float x;
    int n;
    cin>>x>>n;
    cout<<myPow2(x,n)<<endl;
    return 0;
}
#include<iostream>
using namespace std;
int gcd(int a, int b){
    //rec case
    if(a == 0)  return b;

    //rec cae
    return gcd(b%a, a);
}
bool coprimes(int a, int b){
    if(gcd(a,b) == 1){
        return true;
    }
    return false;
}
int eulerPhi(int n){
    int cnt  = 0;
    for(int i = 1; i<n; i++){
        if(coprimes(i,n)){
            cnt++;
        }
    }
    return cnt;
}
int main()
{   
    int n;
    cin>>n;
    cout<<eulerPhi(n)<<endl;
    return 0;
}
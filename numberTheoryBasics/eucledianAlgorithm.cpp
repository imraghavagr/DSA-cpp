//eucledian algorithm is used to find gcd(a,b)
#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(a == 1){
        return b;
    }
    return gcd(b%a, a);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}
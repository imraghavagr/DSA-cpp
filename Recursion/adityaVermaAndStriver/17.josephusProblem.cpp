//game of death 
#include<iostream>
using namespace std;
int josephus(int n,int k){
    if(n==1)
        return 1;

    return (josephus(n-1,k)+k)%n;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<josephus(n,k)<<endl;
    return 0;
}
#include<iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    int a = 9, b = 11;
    for(int i = 0; i<n; i++){
        if(i==0)cout<<a<<" ";
        else if(i==1)cout<<b<<" ";
        else{
            cout<<a+b<<" ";
            int temp = a;
            a = b;
            b = temp+b;
        }
    }
    cout<<endl;
    return 0;
}
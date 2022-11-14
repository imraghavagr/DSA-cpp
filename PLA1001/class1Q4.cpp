#include<iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    int prev = 5;
    int multiplyNum = 1;
    for(int i = 0; i<n; i++){
        cout<<prev+multiplyNum<<" ";
        prev = prev+multiplyNum;
        multiplyNum = 5*(i+1);
    }
    cout<<endl;
    return 0;
    +
}
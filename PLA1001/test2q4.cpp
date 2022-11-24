#include<iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    int startingNum = 4;
    int prev = 4;
    for(int i = 0; i<n; i++){
        if(i==0)cout<<startingNum<<" ";
        else{
            int num = startingNum + (i*i);
            cout<<num<<" ";
            startingNum = num;
        }
    }
    cout<<endl;
    return 0;
}
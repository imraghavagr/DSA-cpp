#include<iostream>
#include<stack> 
using namespace std;
int solve(int n){
    stack<int> stk;
    int len = 0;
    while(n>0){
        len++;
        stk.push(n%10);
        n = n/10;
    }
    int mf = 1;
    int num = 0;
    while(!stk.empty()){
        num += (stk.top()*mf);
        mf *= 10;
        stk.pop();
    }
    return num;
}
int main()
{   
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}
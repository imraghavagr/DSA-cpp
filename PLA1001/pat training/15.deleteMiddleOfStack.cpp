#include<iostream>
#include<stack>
using namespace std;
void deleteMiddle(stack<int> &stk, int k){
    if(k == 1){
        stk.pop();
        return;
    }
    
    //hypothesis - solve for smaller input 
    int temp = stk.top();
    stk.pop();
    deleteMiddle(stk, k-1);
    
    //induction - put back the temp
    stk.push(temp);
}
int main()
{   
    stack<int> stk;
    for(int i = 1; i<=5; i++){
        stk.push(i);
    }
    int middle  = (stk.size()/2) + 1;
    deleteMiddle(stk, middle);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}
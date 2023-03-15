#include<iostream>
#include<stack>
using namespace std;
void deleteMiddleElement(stack<int> &stk, int k){
    if(k == 1){
        stk.pop();
        return;
    }
    
    //hypothesis - solve for smaller input 
    int temp = stk.top();
    stk.pop();
    deleteMiddleElement(stk, k-1);
    
    //induction - put back the temp
    stk.push(temp);
}
int main()
{   
    stack<int> stk;
    stk.push(7);
    stk.push(5);
    stk.push(2);
    stk.push(4);
    stk.push(3);
    int k = stk.size()/2 + 1;
    deleteMiddleElement(stk, k);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}
#include<iostream>
#include<stack>
using namespace std;
void putIntoBottom(stack<int> &stk, int num){
    if(stk.size() == 0){
        stk.push(num);
        return;
    }
    int temp = stk.top();
    stk.pop();
    putIntoBottom(stk, num);
    stk.push(temp);
}
void reverseStack(stack<int> &stk){
    if(stk.size() == 1) return;

    int temp = stk.top();
    stk.pop();

    reverseStack(stk);

    //put temp in the bottom of the stack using a different recursive function 
    putIntoBottom(stk, temp);
}
int main()
{   
    stack<int> stk;
    stk.push(7);
    stk.push(5);
    stk.push(2);
    stk.push(4);
    stk.push(3);
    reverseStack(stk);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}
#include<iostream>
#include<stack>
using namespace std;
void insert(stack<int>& stk, int temp){
    //base condition 
    if(stk.empty() || temp <= stk.top()){
        stk.push(temp);
        return;
    }
    //hypothesis - solve for smaller input 
    int val = stk.top();
    stk.pop();
    insert(stk, temp);

    //induction - put val at the correct positon 
    stk.push(val);
}
void mySort(stack<int>& stk){
    //base case
    if(stk.size() == 1)return;

    //hypothesis - solve for smaller input 
    int temp = stk.top();
    stk.pop();
    mySort(stk);

    //induction - put temp in its correct position in sorted stk with smaller input 
    insert(stk, temp);
}
int main(){

    stack<int> stk;
    int n,num;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>num;
        stk.push(num);
    }
    // while(!stk.empty()){
    //     cout<<stk.top()<<" ";
    //     stk.pop();
    // }
    // cout<<endl;
    mySort(stk);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}
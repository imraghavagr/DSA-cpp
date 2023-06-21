#include<iostream>
#include<vector>
using namespace std;
//we will use 
class Stack{
    vector<int> v;
public:
    void push(int x){
        //we need to push x into the top of the stack -> end of the vector will represnt top for us 
        //we will push x into the top 
        v.push_back(x);
    }
    int top(){
        if(v.empty())   return -1; 
        else    return v.back();
    }
    void pop(){
        //check if the stack is empty or not 
        if(!v.empty())  v.pop_back();
    }
};
int main()
{   
    Stack stk; 
    for(int i = 1; i<=5; i++)   stk.push(i);
    stk.pop(); 
    cout<<stk.top()<<endl;;
    for(int i = 1; i<=4; i++)   stk.pop();
    //stack is empty now 
    cout<<stk.top()<<endl;
    return 0;
}
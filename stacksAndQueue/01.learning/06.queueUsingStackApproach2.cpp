#include<iostream>
#include<stack>
using namespace std;
//here also we will use two stacks, one input stack and one output stack 
//Time Complexity for push -> O(1), Amortised TC for pop and top -> O(1)
//Space Complexity O(2n)
/*
Algorithm:
    For push(x) : insert x into input stk 

    For pop()   : if output stk is empty, first transfer element from input stack to output stak and then do outputStk.pop()
                  else  outputStk.pop();
    
    For front() : if output stk is empty, first transfer element from  input stack to output stk and then return outputStk.top();
                  else outputStk.top();
*/
class Queue{
    stack<int> input, output; 
    public:
    void push(int x){
        input.push(x);
    }
    int top(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
        else    return output.top();
    }
    void pop(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.pop();
        }
        else    return output.pop();
    }
};
int main()
{   
    Queue q; 
    q.push(2);
    q.push(5);
    q.push(3);
    cout<<q.top()<<endl;
    q.pop();
    q.push(6);
    q.pop();
    q.pop();
    cout<<q.top()<<endl;
    return 0;
}
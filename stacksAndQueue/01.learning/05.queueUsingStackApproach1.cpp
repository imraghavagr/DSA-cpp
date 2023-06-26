#include<iostream>
#include<stack>
using namespace std;
//using two stacks - stk1, stk2 .. stk1 is the main stack here 
class Queue{
    stack<int> s1, s2;
    public:
    void push(int x){
        //first transfer all elements from s1 to s2 
        while(!s1.empty()){
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        s1.push(x);
        //now transfer all elements back from s2 to s1 
        while(!s2.empty()){
            int temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
    } 
    void pop(){
        if(!s1.empty()){
            s1.pop();
        }
    }
    int top(){
        if(!s1.empty()){
            return s1.top();
        }
        return -1; 
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
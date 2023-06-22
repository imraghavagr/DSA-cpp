//we will have to use an extra queue to impllement stack using queue
#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int> q; 
    queue<int> temp; 
    public:
    void Push(int x){
        //push x into q2 .. copy all elements from q1 into q2 one by one and then swap q1,q1
        temp.push(x);
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        swap(q,temp);
    }
    int top(){
        return q.front();
    }
    void Pop(){
        q.pop();
    }
    bool isEmpty(){
        return q.empty() == true;
    }
};
int main()
{   
    Stack stk; 
    stk.Push(3);
    stk.Push(4);
    stk.Push(2);
    stk.Push(1);
    cout<<stk.top()<<endl;
    stk.Pop();
    cout<<stk.top()<<endl;
    while(!stk.isEmpty()){
        cout<<stk.top()<<" ";
        stk.Pop();
    }
    cout<<endl;
    return 0;
} 
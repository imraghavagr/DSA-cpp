#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int> q; 
    int size; 
public:
    Stack(){
        size = 0;
    }
    void push(int x){
        q.push(x);
        size += 1;
        //now pop and push size-1 elements from the queue 
        for(int i = 1; i<size; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    void pop(){
        q.pop();
    }
    int top(){
        return q.front();
    }
    bool isEmpty(){
        return q.empty();
    }
};
int main()
{   
    Stack stk; 
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    while(!stk.isEmpty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
    return 0;
}
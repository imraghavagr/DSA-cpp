//stack follows LIFO -> Last In First Out
//Static Queue implementation using array 
#include<iostream>
using namespace std;
//it will give overflow/underflow error if we try to insert an element after the stack is full
// or if we will try to pop an element from an empty stack
class Stack{
    int *arr; 
    int size;
    int top;
public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int x){
        arr[++top] = x; 
    }
    int pop(){
        return arr[top--];
    }
    int Top(){
        return arr[top];
    }
    int Size(){
        return top+1; 
    }
};
int main()
{   
    Stack stk(5);
    for(int i = 1; i<=5; i++){
        stk.push(i);
    }
    cout<<stk.pop()<<endl;
    cout<<stk.Top()<<endl;
    cout<<stk.pop()<<endl;
    cout<<stk.Top()<<endl;
    cout<<stk.Size()<<endl;
    return 0;
}
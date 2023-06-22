//queue follows FIFO (FIRST IN FIRST OUT)
//implementation of static queue using arrays [cyclic array]
#include<iostream>
using namespace std;
class Queue{
    int *arr; 
    int size;
    int front, rear,cnt;
public:
    Queue(int s){
        size = s; 
        arr = new int[size];
        front = 0; 
        rear = 0; 
        cnt = 0;
    }
    void push(int x){
        //we need to push x into rear of the queue 
        //queue is full
        if(cnt == size) return; 
        //if it is not full 
        arr[rear%size] = x;
        rear ++;
        cnt++;
    }
    void pop(){
        //queue is empty
        if(cnt == 0)    return; 
        //put any dummy number in place of front
        arr[front % size] = -1; 
        front++;
        cnt--;

    }
    int top(){
        if(cnt == 0)    return -1; 
        return arr[front % size];
    }
    bool isEmpty(){
        return cnt == 0;
    }
};
int main()
{   
    Queue q(5);
    q.push(3);
    q.push(2);
    q.push(1);
    q.push(8);
    q.push(6);
    q.push(7);
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.push(9);
    q.pop();
    q.push(10);
    while(!q.isEmpty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
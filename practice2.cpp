#include<iostream>
using namespace std;
class node{
public
    int data;
    node * next;
    node(int d){
        data=d;
        next=NULL;
    }
};
int main(){
    node * head=NULL;
    head=new node(1);
    cout<<head->next;
    
    return 0;
}
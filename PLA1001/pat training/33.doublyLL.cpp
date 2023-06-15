#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};
void insertAtHead(Node* &head, Node* &tail, int d){
    if(head == NULL){
        head = new Node(d);
        tail = head;
        return;
    }
    //remaining insertions 
    Node* n = new Node(d);
    n->next = head;
    head->prev = n;
    head = n;
}
void printForward(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void printBackward(Node* tail){
    while(tail != NULL){
        cout<<tail->data<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}
int main()
{   
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    printForward(head);
    printBackward(tail);
    return 0;
}
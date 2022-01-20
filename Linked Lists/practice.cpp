#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node*next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
void insertAtHead(Node*&head, int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node*n = new Node(d);
    n->next = head;
    head = n;
}
void printLL(Node*head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head -> next;
    }
    cout<<endl;
}
int main(){
    Node* head = NULL;
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printLL(head);
    return 0;
}
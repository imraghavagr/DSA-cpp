#include<iostream>
using namespace std;
/*
            100        200         300         400
h = 100    1 200      2 300       3 400      4 NULL
*/
class node{
public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(node*&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = head;
    head = n;
}
void printLL(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

int main(){

    node* head = NULL;
    printLL(head);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printLL(head);
    return 0;
}
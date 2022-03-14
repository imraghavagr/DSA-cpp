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
void insertAtHead(node* &head, int d){
    //head's datatype is node* and it is passed by reference, therefore node*&head
    if(head == NULL){
        //first node insertion
        head = new node(d);
        return;
    }
    //insertion for remaining nodes
    node* temp = new node(d); //create a temp node
    temp->next = head; //temp's next will store the address stored in head
    head = temp; // head will point to new node i.e. temp
}

void insertAtTail(node*&head, int d){
   if(head == NULL) {
       //empty ll
       head = new node(d);
       return;
   }
   //traverse the linked list and get the tail pointer 
   node* tail = head;
   while(tail->next != NULL){
       tail = tail->next;
   }
   node *temp = new node(d);
   tail->next = temp;
}
void printLL(node*head){
    while(head != NULL){
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

    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    printLL(head);
    return 0;
}
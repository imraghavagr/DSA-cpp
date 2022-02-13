#include<iostream>
using namespace std;
/*
                    100          500          200          250
    head = 100      1|500  ->    2|200  ->    3|250  ->    4|NULL
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
void insertAtTail(node*&head, int d){
    //without mainting a tail
    if(head == NULL){
        
    }
    node* temp = head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    node* n = new node(d);
    temp -> next = n;
}

void reverseLL(node*&head){
    if(head == NULL){
        return;
    }
    node*P = NULL;
    node*C = head;
    node*N;
    while(C != NULL){
        N = C -> next;
        C -> next = P;

        P = C;
        C = N;
    }
    head = P;

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
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtTail(head,12);
    printLL(head);
    reverseLL(head);
    printLL(head);
    return 0;
}
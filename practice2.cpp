#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
void insertAtHead(Node* &head, Node* &tail, int d){
    if(head == NULL){
        //first insertion 
        head = new Node(d);
        tail = head;
        return;
    }
    //for remaining insertions 
    Node* n = new Node(d);
    n->next = head;
    head = n;
}
void insertAtTail(Node* &head, Node*& tail, int d){
    if(head == NULL){
        //first insertion 
        head = new Node(d);
        tail = head;
        return;
    }
    //remaining insertions 
    Node* n = new Node(d);
    tail->next = n;
    tail = n;
}
int lenLL(Node* head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}
void insertAtPos(Node* &head, Node* &tail, int pos, int d){
    if(pos == 0){
        insertAtHead(head, tail, d);
        return;
    }
    if(pos >= lenLL(head)){
        insertAtTail(head, tail, d);
        return;
    }
    
    Node* prev = head;
    Node* curr = head;
    while(pos--){
        prev = curr;
        curr = curr->next;
    }
    Node* n = new Node(d);
    prev->next = n;
    n->next = curr;
}
void deleteAtHead(Node* &head){
    if(head == NULL)    return;
    Node* temp = head->next;
    delete head;
    head = temp;
}
void deleteAtTail(Node* &head){
    Node* curr = head;
    Node* prev = head;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete curr;
}
void deleteAtPos(Node* &head, int pos){
    if(pos == 0){
        deleteAtHead(head);
        return;
    }
    if(pos >= lenLL(head)){
        deleteAtTail(head);
        return;
    }
    Node* curr = head;
    Node* prev = head;
    while(pos--){
        prev = curr;);
    printLL(head);
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
}
void printLL(Node* head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
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
    printLL(head);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    printLL(head);

    insertAtPos(head, tail, 3, 5);
    printLL(head);
    insertAtPos(head, tail, 0, 0);
    printLL(head);
    insertAtPos(head, tail, 100, 10);
    printLL(head);

    deleteAtPos(head, 0);
    printLL(head);
    deleteAtPos(head, 100);
    printLL(head);
    deleteAtPos(head, 4);
    printLL(head);
    return 0;
}
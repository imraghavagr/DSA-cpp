#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
void insertionAtHead(Node* &head, int d){
    if(head == NULL){
        //first insertion 
        head = new Node(d);
        return;
    }
    //remaining insertions 
    Node* n = new Node(d);
    n->next = head;
    head = n;
}
void printLL(Node* head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
void changePointers(Node* &head, Node* &tail, Node* temp){
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }    
}
Node* oddBeforeEven(Node* &head){
    Node* oddHead = NULL;
    Node* oddTail = NULL;
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* temp = head;

    while(temp != NULL){
        //odd
        if((temp->data) & 1)    changePointers(oddHead, oddTail, temp);
        //even
        else    changePointers(evenHead, evenTail, temp);
        temp = temp->next;
    }

    //now join the head of evenHead at the last of odd head i.e. at its tail 
    oddTail->next = evenHead;
    evenTail->next = NULL;
    return oddHead;
}
int main()
{
    Node* head = NULL;
    int x;
    cin>>x;
    while(x != -1){
        insertionAtHead(head, x);
        cin>>x;
    }
    printLL(head);
    head = oddBeforeEven(head);
    printLL(head);
    return 0;
}
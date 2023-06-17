#include<iostream>
#include<climits>
using namespace std;
class Node{
public:
    Node* next; 
    int data;
    Node(int d){
        data = d;
        next = NULL;
    }
};
void insertAtHead(Node* &head, int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node* n = new Node(d);
    n->next = head;
    head = n;
}
void printAndFindMax(Node* head){
    int maxe = INT_MIN;
    while(head != NULL){
        maxe = max(maxe, head->data);
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
    cout<<maxe<<endl;
}
int main()
{   
    Node* head = NULL;
    for(int i = 5; i>0; i--)    insertAtHead(head, i);
    printAndFindMax(head);
    return 0;
}
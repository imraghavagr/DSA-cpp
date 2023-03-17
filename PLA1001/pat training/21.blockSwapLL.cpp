#include<iostream>
using namespace std;
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
    
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = head;
    head = n;
}
int findLengthLL(node* head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}
void blockSwap(node* &head, int d){
    int n = findLengthLL(head);
    if(d <= 0 || d>=n)  return;

    node* temp = head;
    node* tail = head;
    node* prev;
    int i = 0;
    while(tail->next != NULL){
        if(i<d){
            prev = temp;
            temp = temp->next;
            i++;
        }
        tail = tail->next;
    }
    cout<<prev->data<<" "<<temp->data<<" "<<tail->data<<endl;

    //break the link 
    prev->next = NULL;
    tail->next = head;
    head = temp;
}
void printLL(node* head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
int main()
{   
    node* head = NULL;
    int n,x,d;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>x;
        insertAtHead(head, x);
    }
    printLL(head);
    cin>>d;    
    blockSwap(head, d);
    printLL(head);
    return 0;
}
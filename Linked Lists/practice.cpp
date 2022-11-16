#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node* prev;

        node(int d){
            data = d;
            next = NULL;
            prev = NULL;
        }
};

void insertAtHead(node*&head, node*&tail, int d){
    if(head == NULL){
        head = new node(d);
        tail = head;
        return;
    }

    //input the remaining nodes
    node* n = new node(d);
    n->next = head;
    head->prev = n;
    head = n;
}
void printLL(node*head, node*tail){
    while(head != NULL){
        cout<<head->data<<" -> ";
        head = head -> next;
    }
    cout<<endl;
    while(tail!=NULL){
        cout<<tail->data<<" -> ";
        tail = tail->prev;
    }
    cout<<endl;
}
int main()
{   
    node* head = NULL;
    node* tail = NULL;

    int n;
    cin>>n;
    
    int x;
    for(int i = 0; i<n; i++){
        cin>>x;
        insertAtHead(head,tail,x);
    }

    printLL(head, tail);

    return 0;
}
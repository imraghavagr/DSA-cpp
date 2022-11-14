#include<iostream>
using namespace std;
class node{
    public:
        node* next;
        int data;

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
    //insertion for remaining nodes
    node*n = new node(d);
    n->next = head;
    head = n;
}
void printLL(node* head){
    while(head != NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{   
    node* head = NULL;
    int n;
    cin>>n;
    int x;
    for(int i = 0; i<n; i++){
        cin>>x;
        insertAtHead(head,x);
    }
    printLL(head);
    return 0;
}
#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* prev;
        node* next;

        node(int d){
            data = d;
            prev = NULL;
            next = NULL;
        }
};
void insertAtHead(int d, node*&head, node*&tail){
    if(head==NULL){
        head = new node(d);
        tail = head;
        return;
    }
    //inserting remaining nodes
    node* n = new node(d);
    n->next = head;
    head->prev = n;
    head = n;
    head->prev = NULL;
}
void printLL(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void segregateEvenOdd(node*&head,node*&tail){
    node*oddStart = NULL;
    node*oddEnd = NULL;
    node*evenStart = NULL;
    node*evenEnd = NULL;
    node* temp = head;
    while(temp != NULL){
        if((head->data)&1){
            //odd 
            if(oddStart == NULL){
                oddStart = temp;
                oddEnd = temp;
                oddStart->prev = NULL;
            }
            else{
                oddEnd->next = temp;
                node*temp2 = oddEnd;
                oddEnd = temp;
                oddEnd->prev = temp2;
            }
        }
        else{
            //even
            if(evenStart == NULL){
                evenStart = temp;
                evenEnd = temp;
                evenStart->prev = NULL;
            }
            else{
                evenEnd->next = temp;
                node*temp2 = evenEnd;
                evenEnd = temp;
                evenEnd->prev = temp2;
            }
        }
        temp = temp->next;
    }
    if(evenStart == NULL || oddStart == NULL){
        return;
    }

    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    head = evenStart;
}
int main()
{   
    node*head = NULL;
    node*tail = NULL;
    int n,x;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>x;
        insertAtHead(x,head,tail);
    }
    printLL(head);
    segregateEvenOdd(head,tail);
    printLL(head);
    return 0;
}
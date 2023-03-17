#include<iostream>
#include<unordered_set>
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
        //first insertion 
        head = new node(d);
        return;
    }
    //insert remaining nodes
    node* n = new node(d);
    n->next = head;
    head = n;
}
void display(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
void removeDuplicates(node* &head){
    unordered_set<int> st;

    node* curr = head;
    node* prev;

    while(curr != NULL){
        prev = curr;
        if(st.find(curr->data) == st.end()){
            st.insert(curr->data);
            curr = curr->next;
        }
        else{
            //this is a duplicate .. remove it 
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
    }
}
int main()
{   
    node* head = NULL;
    insertAtHead(head, 3);   
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 5);
    display(head);
    cout<<endl;
    removeDuplicates(head);
    display(head);
    cout<<endl;
    return 0;
}
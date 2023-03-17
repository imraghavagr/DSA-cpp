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
void printLL(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
bool isTrendy(node* head){
    int n = findLengthLL(head);

    int mid = n/2 ;
    int cnt = 0;
    
    node* prev = head;
    node* curr = head;
    while(cnt < mid){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if(n&1){
        //odd
        if(curr->data % 3 == 0) return true;
        else return false;
    }
    else{
        if((prev->data + curr->data )%3 == 0)    return true;
        else    return false;
    }
}
int main()
{   
    int n;
    cin>>n;
    int x;
    node* head = NULL;
    for(int i = 0; i<n; i++){
        cin>>x;
        insertAtHead(head, x);
    }
    printLL(head);
    // isTrendy(head);
    if(isTrendy(head)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
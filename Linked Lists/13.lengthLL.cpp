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
void insertAtHead(node*&head, int d){
	
	if(head == NULL){
		//first node in ll
		//earlier head was pointing to null, now it will point to the new node containing data - 'd'
		head = new node(d); //now head will store the address of the first node in LL 
		return;
	}
	//case when we are inserting any node other than the first node
	//naya node basically, head aur first node ke beech me ghusta hai
	node *n = new node(d);
	n -> next = head; // or (*n).next = head;
	head = n;

}
void printLL(node*head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}
node* take_input(){
	int d;
	cin>>d;
	node* head = NULL;
	while(d!=-1){
		insertAtHead(head,d);
		cin>>d;
	}
	return head;
}
ostream& operator<<(ostream &os, node* head){
	printLL(head);
	return os; //cout object returned
}
istream& operator>>(istream &is, node*&head){
	head = take_input();
	return is;
}
int fastLengthLL(node* head){
    node* fast = head;
    int cnt = 0;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        cnt += 2;
    }
    if(fast == NULL)return cnt;
    else    return cnt+1;
}
int main(){
    node* head = NULL;
    cin>>head;
    cout<<head<<endl;
    cout<<fastLengthLL(head)<<endl;
}

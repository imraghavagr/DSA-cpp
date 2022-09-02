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
int midPoint(node*head){
    if(head == NULL){
        return -1; //return -1 if the ll is empty.
    }
    node*slow = head;
    node*fast = head;
    while(fast->next != NULL and fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int main(){

	node*head;
	cin>>head;
	cout<<head;
	node* mid = midPoint(head);

	cout<<mid->data<<endl;
	return 0;
}

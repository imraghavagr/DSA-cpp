//find the kth node from the end, of a ll
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
int lengthLL(node*head){
	int len = 0;
	while(head != NULL){
		len++;
		head = head->next;
	}
	return len;
}
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

node* solve(node* a, node* b){
	
	//base case
	if(a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}

	//take a new head pointer
	node*c;
	if(a->data < b->data){
		c = a;
		c->next = solve(a->next,b);
	}
	else{
		c = b;
		c -> next = solve(a,b->next);
	}

	return c;
}

int main(){

	node*head1;
	node*head2;
	cin>>head1;
	cin>>head2;
	cout<<head1;
	cout<<head2;
	cout<<"merged ll: "<<endl;
	node* c = solve(head1,head2);
	cout<<c<<endl;
	return 0;
}

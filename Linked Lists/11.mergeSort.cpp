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

node* merge(node* a, node* b){
	
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
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c -> next = merge(a,b->next);
	}

	return c;
}

node* midPoint(node* head){
	
	if(head == NULL or head->next == NULL){
		return head;
	}

	node*slow = head;
	node*fast = head->next;

	while(fast !=NULL and fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node* mergeSort(node* head){

	//base case - ll with 0 or 1 node
	if(head == NULL or head->next == NULL){
		return head;
	}

	//rec case
	//1 - Divide
	node*mid = midPoint(head);
	node*a = head;
	node*b = mid->next;

	mid->next = NULL;

	//2. rec sorting a and b
	a = mergeSort(a);
	b = mergeSort(b);

	//3. merge them
	node*c = merge(a,b);
	return c;
}

int main(){

	node*head;
	cin>>head;
	cout<<head;
	head = mergeSort(head);
	cout<<head<<endl;
	return 0;
}

#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int d){
		data = d;
		next = NULL;
	}
};

void insertAtHead(Node*&head, int d){
	
	if(head == NULL){
		//first node in ll
		//earlier head was pointing to null, now it will point to the new node containing data - 'd'
		head = new Node(d); //now head will store the address of the first node in LL 
		return;
	}
	//case when we are inserting any node other than the first node
	//naya node basically, head aur first node ke beech me ghusta hai
	Node *n = new Node(d);
	n -> next = head; // or (*n).next = head;
	head = n;

}

void insertAtTail(Node*&head,int d){
	if(head == NULL){
		head = new Node(d);
		return;
	}
	Node*tail = head;
	while(tail->next!=NULL){
		tail = tail->next;
	}
	tail->next = new Node(d);
	return;
}

int length(Node*head){
	int cnt = 0;
	while(head!=NULL){
		cnt++;
		head = (*head).next;
		//or head = head->next;
	}
	return cnt;
}

//p -> position at which node is to be inserted
// p = 0 - means, we are inserting from head
//for LL= 0 -> 1 -> 2 -> 4, if p = 2, d = 3
//new LL will be : 0>1>3>2>4
//p>len of ll, insertion at tail

void insertFromMiddle(Node*&head,int d, int p){
	if(head == NULL or p == 0){
		insertAtHead(head,d);
		return;
	}
	else if(p>=length(head)){
		//insert at tail
		insertAtTail(head,d);
		return;
	}
	else{
		//insert in the middle
		//reach temp node by taking p-1 jumps
		int jump = 1;
		Node*temp = head;
		while(jump<=p-1){
			temp = temp->next;
			jump++;
		}
		//create a new node
		Node*n = new Node(d);
		n->next = temp->next;
		temp->next = n;

	}
}
void printLL(Node*head){
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head = head->next;
	}
	cout<<endl;
}
int main(){

	Node* head = NULL; // will store the address of the first node of ll
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,0);

	insertFromMiddle(head,4,3);
	printLL(head);

	insertFromMiddle(head,5,0);
	printLL(head);

	insertFromMiddle(head,11,10);
	printLL(head);

	insertFromMiddle(head,8,2);
	printLL(head);

	return 0;
}

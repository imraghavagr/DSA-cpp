#include<iostream>
using namespace std;

class node{
public:
	int data; 
	node* next; //next will store the address of the next node

	//ctor
	node(int d){
		data = d;
		next = NULL; // in the begining there will be no next node
	}
};

//Linked Class(object oriented)
/*class LinkedList{ 
	node* head;
	node* tail;
public:
	LinkedList(){

	}
	void insert(int d){
	
	}
}*/

//LL implementation using Functions - Procedural programming

//we need to pass the head pointer value by ref

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
	n -> next = head; // or *n.next  = head
	head = n;

}
void printLL(node*head){
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head = head->next;
	}
	cout<<endl;
}

int main(){

	node* head = NULL; // will store the address of the first node of ll
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,0);
	printLL(head);
	printLL(head);
	return 0;
}

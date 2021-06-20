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
void insertFromHead(Node*&head,int d){
	if(head == NULL){
		//this means we are inserting first element into ll
		head = new Node(d);
		return;
	}
	//for inserting remaining elements
	Node *n = new Node(d);// n will store the address of new node
	(*n).next = head;
	head = n;
}
/*void insertFromTail(Node*&tail, int d){
	if(tail == NULL){
		//first element
		tail = new Node(d);
		return;
	}
	Node*n = new Node(d);
	(*tail).next = n;
	tail = n;
}*/
void printLL(Node*head){
	while(head!=NULL){
		cout<<(*head).data<<"->";
		head = (*head).next;
	}
	cout<<endl;
}
int main(){

	Node*head = NULL;
	insertFromHead(head,1);
	insertFromHead(head,2);
	insertFromHead(head,3);
	insertFromHead(head,4);
	insertFromHead(head,5);
	printLL(head);

	//lets make an another ll and this time we will insert the elements form tail
	Node*tail = NULL;
	insertFromTail(tail,5);
	insertFromTail(tail,4);
	insertFromTail(tail,3);
	insertFromTail(tail,2);
	insertFromTail(tail,1);
	printLL(tail);

	return 0;
}

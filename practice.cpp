#include<iostream>
using namespace std;
/*

		100			200			300			400
h 100	1 200		2 300		3 400		4 NULL	 

			10000
h = 10000	5	Null

				10			10000
h = 10000		4 NULL		5  NULL

				10			10000
h = 10	->		4 10000	->	5  NULL

*/
class node{
public:
	int data;
	node* next;
	node(int d)	{
		data = d;
		next = NULL;
	}
};
void insertAtMiddle(int d, node*&head, int p){
	
}
void insertAtHead(int d, node*&head){
	if(head == NULL){
		head = new node(d);
		return;
	}
	node* n = new node(d);
	n->next = head;
	head = n;
}

void insertAtTail(int d, node*&head){
	if(head == NULL){
		head = new node(d);
		return;
	}
	node*temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	node* n = new node(d);
	temp->next = n;
}
void printLL(node*head){
	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}
int main(){
	
	node*head = NULL;
	insertAtTail(6,head);
	insertAtHead(5,head);
	insertAtHead(4,head);
	insertAtHead(3,head);
	insertAtHead(2,head);
	insertAtHead(1,head);
	insertAtTail(7,head);
	printLL(head);
	printLL(head);
	return 0;
}
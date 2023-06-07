//iterative appr - o(n) time + o(1) space
//recursive appr - o(n) time + o(n) stack space
//iterative appr is more efficient
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
void reverseLL(node*&head){
	node* C = head;
	node*N;
	node*P = NULL;
	while(C!=NULL){
		//save the next node
		N = C->next;
		//make the current node point to P
		C->next = P;

		//update P and C take them 1 step forward
		P = C;
		C = N;
	}
	head = P;
}
node* reverseRecursively(node*head){
	//base case - smallest ll that we need to reverse
	//ll with one node or zero node
	if(head->next == NULL or head == NULL){
		return head;
	}
	//rec case
	node* sHead = reverseRecursively(head->next);
	
	node* temp = head->next;
	temp->next = head;
	head->next = NULL;
	
	return sHead;
}

void printLL(node* head){
	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}
int main(){
	node* head = NULL;
	insertAtHead(head,1);
	insertAtHead(head,2);
	insertAtHead(head,3);
	insertAtHead(head,4);
	insertAtHead(head,5);
	printLL(head);
	reverseLL(head);
	printLL(head);
	head = reverseRecursively(head);
	printLL(head);
	return 0;
}
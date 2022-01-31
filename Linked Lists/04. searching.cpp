#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*next;
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
void printLL(Node*head){
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head = head->next;
	}
	cout<<endl;
}

bool search(Node*head,int key){
	//linear search
	while(head != NULL){
		if(head->data == key){
			return true;
		}
		head = head->next;
	}
	return false;
}
//recursive search fun
bool recSearch(Node*head, int key){
	//base case
	if(head == NULL){
		return false;
	}

	//rec case
	if(head->data == key){
		return true;
	}
	else{
		return recSearch(head->next, key);
	}
}
int main(){

	Node* head = NULL; // will store the address of the first node of ll
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,0);
	printLL(head);
	int key;
	cin>>key;
	if(recSearch(head,key)){
		cout<<"Element found"<<endl;
	}
	else{
		cout<<"Element not found"<<endl;
	}
	return 0;
}

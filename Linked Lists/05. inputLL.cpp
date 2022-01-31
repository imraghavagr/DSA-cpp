#include<iostream>
using namespace std;
//asking user to enter data to a LL
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
void printLL(Node* head){
	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

Node* take_input_2(){
	int d;
	cin>>d;
	Node* head = NULL;
	while(d!=-1){
		insertAtHead(head,d);
		cin>>d;
	}
	return head;
}

//taking ip from file - 'input.txt'
//usefull when the input file does not contain -1 at eof

//for running:
//g++ inputLL.cpp -o a
//a < input.txt
Node* take_input_1(){
	int d;
	Node*head = NULL;
	while(cin>>d){
		insertAtHead(head,d);
	}
	return head;
}
int main(){

	
	//will accept inputs untill -1 is entered
	//Node* head = take_input_2();

	Node*head = take_input_1();
	printLL(head);


	return 0;
}

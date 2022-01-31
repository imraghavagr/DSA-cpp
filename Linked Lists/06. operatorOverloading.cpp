#include<iostream>
using namespace std;

//cout<<head.. will give the address stored at head that is address of first node of LL
//we want to overload << and >> operator
//s.t. cout<<head will give print entire ll
//and cin>>head will take LL elements as input

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

// cout<<head; --> here there are two objects
//first is 'cout' that is object of ostream
//and second is 'head' that is of type node*
//we need to pass these two parameters inside our function definition

/*void operator<<(ostream &os, node* head){
	printLL(head);
	return;
}*/

//above function will work fine for cout<<head.
//but it wont work wor cout<<head1<<head2
//because the first two will return void and void<<head2 does not make any sense
//therefore we need to implement cascading along with operator overloading

ostream& operator<<(ostream &os, node* head){
	printLL(head);
	return os; //cout object returned
}
istream& operator>>(istream &is, node*&head){
	head = take_input();
	return is;
}




int main(){

	node*head;
	node*head2;
	cin>>head>>head2;
	cout<<head<<head2;



	return 0;
}

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

int lengthLL(node* head){
	int cnt = 0;
	while(head!=NULL){
		cnt++;
		head = head->next;
	}
	return cnt;
}

void insertAtHead(node*&head, int d){
	if(head == NULL){
		head = new node(d);
		return;
	}
	node*n = new node(d);
	n->next = head;
	head = n;
}
void insertAtTail(node*&head, int d){
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	node* n = new node(d);
	temp->next = n;
}
void insertAtMiddle(node*&head,int d, int p){
	if(head == NULL or p == 0){
		insertAtHead(head,d);
		return;
	}
	if(p>lengthLL(head)){
		insertAtTail(head,d);
		return;
	}
	//insert at middle
	int jump = 1;
	node*temp = head;
	while(jump<=p-1){
		temp = temp->next;
		jump++;
	}
	node* n = new node(d);
	n->next = temp->next;
	temp->next = n;
}
void printLL(node*head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}
void deleteAtHead(node*&head){
	if(head == NULL){
		return;
	}

	node*temp = head->next;
	delete head;
	head = temp;

}
void deleteAtTail(node*&head){
	if(head == NULL){return;}

	node*temp = head;
	node*tail = head;
	while(tail->next != NULL){
		temp = tail;
		tail = tail->next;
	}
	delete tail;
	temp->next = NULL;

}
void deleteAtMiddle(node*&head,int p){
	if(head == NULL){
		return;
	}
	if (p==0)
	{
		deleteAtHead(head);
		return;
	}
	if(p>lengthLL(head)){
		deleteAtTail(head);
		return;
	}
	//delete at middle
	int jump = 1;
	node*temp = head;
	node*prev = head;
	while(jump<=p-1){
		prev = temp;
		temp = temp->next;
		jump++;
	}
	prev->next=temp->next;
	delete temp;
	
}

bool searchRecursively(node*head, int key){
	if(head == NULL){
		return false;
	}
	if(head->data == key){
		return true;
	}
	else{
		return searchRecursively(head->next,key);
	}
}
node* inputLL(){
	int d;
	node* head = NULL;
	while(cin>>d){
		insertAtHead(head,d);
	}
	return head;
}
int main(){

	node*head = NULL;
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,3);
	printLL(head);
	insertAtTail(head,6);
	insertAtTail(head,7);
	insertAtTail(head,8);
	printLL(head);
	insertAtMiddle(head,9,20);
	printLL(head);
	insertAtMiddle(head,2,0);
	printLL(head);
	insertAtMiddle(head,1,0);
	printLL(head);
	insertAtMiddle(head,5,3);
	printLL(head);
	deleteAtHead(head);
	printLL(head);
	deleteAtTail(head);
	printLL(head);
	deleteAtMiddle(head,2);
	printLL(head);
	
	/*int k;
	cin>>k;
	if(searchRecursively(head,k)){
		cout<<"Present"<<endl;
	}
	else{
		cout<<"Key not present"<<endl;
	}*/
	
	node*head2 = inputLL();
	printLL(head2);


	return 0;



}

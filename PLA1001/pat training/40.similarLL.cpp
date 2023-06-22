#include<iostream>
using namespace std;
class node{
public:
	int data; 
	node* next; 

	//ctor
	node(int d){
		data = d;
		next = NULL;
	}
};
void insertAtHead(node*&head, int d){		
	if(head == NULL){
		head = new node(d); 
		return;
	}
	node *n = new node(d);
	n -> next = head; // or (*n).next = head;
	head = n;

}
bool areSimilar(node* head1, node* head2){
    while(head1 != NULL && head2 != NULL){
        if(head1->data != head2->data)  return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    if(head1 != NULL && head2 != NULL)  return false;
    return true;
}
void printLL(node*head){
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head = head->next;
	}
	cout<<endl;
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL; 
    for(int i = 5; i>=1; i--){
        insertAtHead(head1, i);
        insertAtHead(head2, i);
    }
    insertAtHead(head2, 6);
    if(areSimilar(head1, head2))    cout<<"yes"<<endl;
    else    cout<<"no"<<endl;
	return 0;
}

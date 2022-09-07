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
ostream& operator<<(ostream &os, node* head){
	printLL(head);
	return os; //cout object returned
}
istream& operator>>(istream &is, node*&head){
	head = take_input();
	return is;
}
void reverseLL(node* &head){
	
    node*P = NULL;
    node*C = head;
    node*N;
    while(C!=NULL){
        N = C->next;

        //make the current pointer point to prev
        C->next = P;

        //update current and prev pointer
        P = C;
        C = N;
    }
	head = P;
}
//head(10) -> 1,20		2,30	3,NULL
//				10		20		30
// bool checkPalindrome(node* head){
//     cout<<head<<endl;
// 	node* tempLL = head;
//     tempLL = reverseLL(tempLL);
//     cout<<head<<endl;
//     cout<<tempLL<<endl;
//     while(head != NULL){
//         cout<<"comparing "<<tempLL->data<<" and "<<head->data<<endl;
//         if(tempLL->data != head->data){
//             return false;
//         }
//         tempLL = tempLL->next;
//         head = head->next;
//     }
//     return true;
// }
int main(){

	node*head = NULL;
	for(int i = 3; i>=1; i--){
		insertAtHead(head,i);
	}
	
	printLL(head);
	reverseLL(head);
	printLL(head);
	return 0;
}

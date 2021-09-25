//check if a LL contains a cycle or not
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
int lengthLL(node*head){
	int len = 0;
	while(head != NULL){
		len++;
		head = head->next;
	}
	return len;
}
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

/*
below func will only detect if there is a cycle or not
but we will write a code to break that cycle
*/

bool detectCycle(node*head){
	node*fast = head;
	node*slow = head;

	while(fast!=NULL and fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow){
			breakCycle(head,fast);
			return true;
		}
	}
	return false;
}
bool breakCycle(node*&head){
	node*fast = head;
	node*slow = head;
	int flag = 0;
	int cycleExists = 0;
	while(fast!=NULL and fast->next != NULL){

		if(flag == 0){
			fast = fast->next->next;
			slow = slow->next;	
			
			if(fast == slow){
				//keep fast as it is and take slow back to the head of the ll
				cycleExists = 1;
				slow = head;
				flag = 1;
			}
			
		}
		if(flag == 1){
			//means fast and slow have met once, and rn , slow is in the begining and fast is at the last meeting point
			//now both fast and slow has to move one step at a time
			slow = slow->next;
			if(fast->next != slow){
				fast = fast->next;
			}
			fast->next = NULL;
		}
		
	}

	if(cycleExists == 1){
		return true;
	}
	else{
		return false;	
	}
}

int main(){

	node*head;
	cin>>head;
	cout<<head<<endl;

	node*temp  = head;
	node*cycleNode;
	int cnt = 1;
	//making a cycle in the entered LL
	while(head->next != NULL){
		temp = temp -> next;
		cnt++;
		if(cnt == 3){
			cycleNode = temp;
		}
	}
	temp->next = cycleNode;

	cout<<head<<endl;
	
	/*
	if(detectCycle(head)){
		cout<<"cycle exists"<<endl;
	}
	else{
		cout<<"No cycle exists"<<endl;
	}*/

	return 0;
}

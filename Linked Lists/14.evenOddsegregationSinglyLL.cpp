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
void segregateEvenOdd(Node*&head){
    Node* evenStart = NULL;
    Node* evenEnd = NULL;
    Node* oddStart = NULL;
    Node* oddEnd = NULL;

    Node* temp = head;
    
    while(temp!=NULL){
        // cout<<"coming here"<<endl;
        if((temp->data) & 1){
            //odd
            if(oddStart == NULL){
                //first insertion 
                oddStart = temp;
                oddEnd = oddStart;
            }
            else{
                //remaining insertions
                //oddStart will remain same
                oddEnd->next = temp;
                oddEnd = oddEnd->next;
            }
            
        }
        else{
            //even
            if(evenStart == NULL){
                //first insertion 
                evenStart = temp;
                evenEnd = evenStart;
            }
            else{
                //remaining insertions 
                //start will remain the same
                evenEnd->next = temp;
                evenEnd = evenEnd->next;
            }            
        }
        // cout<<"happening"<<endl;
        temp = temp -> next;
    }

    //at the end, if evenStart or oddStart is NULL, this means the linked list is completely even or completely odd
    //therefor no need to change anything 
    if(evenStart == NULL || oddStart == NULL){
        return;
    }

    //put the odd ll at the end of even  
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    head = evenStart;
}
int main(){

    Node* head = NULL;
    int n;
    cin>>n;
    int x;
    for(int i = 0; i<n; i++){
        cin>>x;
        insertAtHead(head,x);
    }
    printLL(head);
    segregateEvenOdd(head);
    printLL(head);
	return 0;
}

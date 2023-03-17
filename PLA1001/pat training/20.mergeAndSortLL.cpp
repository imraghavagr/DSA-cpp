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
void insertAtHead(node* &head, int d){
    if(head == NULL){
        //first insertion 
        head = new node(d);
        return;
    }
    //insertion of remaining nodes 
    node* n = new node(d);
    n->next = head;
    head = n;
}
void printLL(node* head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
node* merge(node* a, node* b){
	
	//base case
	if(a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}

	//take a new head pointer
	node*c;
	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c -> next = merge(a,b->next);
	}

	return c;
}

node* midPoint(node* head){
	
	if(head == NULL or head->next == NULL){
		return head;
	}

	node*slow = head;
	node*fast = head->next;

	while(fast !=NULL and fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node* mergeSort(node* head){

	//base case - ll with 0 or 1 node
	if(head == NULL or head->next == NULL){
		return head;
	}

	//rec case
	//1 - Divide
	node*mid = midPoint(head);
	node*a = head;
	node*b = mid->next;

	mid->next = NULL;

	//2. rec sorting a and b
	a = mergeSort(a);
	b = mergeSort(b);

	//3. merge them
	node*c = merge(a,b);
	return c;
}
int main()
{   

    int n1,n2;
    cin>>n1>>n2;
    int x;
    node* head1 = NULL;
    node* head2 = NULL;
    for(int i = 0; i<n1; i++){
        cin>>x;
        insertAtHead(head1, x);
    }
    for(int i = 0; i<n2; i++){
        cin>>x;
        insertAtHead(head2, x);
    }
    cout<<"Linked List 1: ";
    printLL(head1);
    cout<<"Linked List 2: ";
    printLL(head2);

    //sort ll 1
    head1 = mergeSort(head1);
    //sort ll2
    head2 = mergeSort(head2);
    
    //now we will merge both the sorted linked lists 
    head1 = merge(head1,head2);
    cout<<"Merge and sorted linked list: ";
    printLL(head1);

    return 0;
}
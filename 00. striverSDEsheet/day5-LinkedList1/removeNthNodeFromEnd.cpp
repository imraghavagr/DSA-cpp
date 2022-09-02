#include<iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;
        ListNode(int d){
            data = d;
            next = NULL;
        }
};
void insertAtHead(ListNode*&head, int d){		
	if(head == NULL){
		head = new ListNode(d);
		return;
	}
	ListNode *n = new ListNode(d);
	n -> next = head;
	head = n;
}
void printLL(ListNode*head){
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head = head->next;
	}
	cout<<endl;
}
ListNode* deleteAtHead(ListNode* head){
    ListNode* temp = head->next;
    delete head;
    head = temp;
    return head;
}
ListNode* deleteAtTail(ListNode* head){
    ListNode* tail = head;
    ListNode* prev = head;
    while(tail -> next != NULL){
        prev = tail;
        tail = tail->next;
    }

    delete tail;
    prev->next = NULL;
    return head;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==NULL){
        return NULL;
    }
    if(head->next == NULL && n == 1){
        return NULL;
    }
    if(n == 1){
        return deleteAtTail(head);
    }
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev;
    for(int i = 0; i<n; i++){
        fast = fast->next;
    }
    //now take both fast and slow 1 step ahead
    while(fast != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    if(slow == head){
        return deleteAtHead(head);
    }
    
    //now we need to delete the ListNode at slow pointer
    prev->next = slow->next;
    delete slow;
    return head;    
}

int main(){
    ListNode* head = NULL;
    for(int i = 5; i>=1; i--){
        insertAtHead(head,i);
    }
    printLL(head);

    //lets try to delete the 2nd node from the end
    head = removeNthFromEnd(head,2);
    printLL(head);

    head = removeNthFromEnd(head,4);
    printLL(head);

    head = removeNthFromEnd(head,1);
    printLL(head);
    return 0;
}
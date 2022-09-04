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
ListNode* reverseLL(ListNode* head){
    //smallest linked list - ll with 0 or 1 node
    if(head == NULL || head->next == NULL){
        return head;
    }

    //recursively reverse the linkedlist from 2nd node to last node and store the head of reversed ll in sHead
    ListNode* sHead = reverseLL(head->next);

    //now sHead contains the reversed ll from 2nd node to last node
    ListNode* temp = head->next;
	temp->next = head;
	head->next = NULL;
	
	return sHead;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    int carry = 0;
    ListNode* l3 = NULL;
    //first traverse both the linked lists
    while(l1 != NULL && l2 != NULL){
        int x = l1->data;
        int y = l2->data;
        insertAtHead(l3,(x+y+carry)%10);
        carry = (x+y+carry)/10;
        l1 = l1->next;
        l2 = l2->next;
    }

    //now traverse whichever ll is remaining 
    while(l1 != NULL){
        insertAtHead(l3,(l1->data + carry)%10);
        carry = (l1->data + carry)/10;
        l1=l1->next;
    }
    while(l2 != NULL){
        insertAtHead(l3,(l2->data + carry)%10);
        carry = (l2->data + carry)/10;
        l2=l2->next;
    }
    if(carry>0){
        insertAtHead(l3,carry);
    }
    return reverseLL(l3);
}
int main(){
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    
    insertAtHead(l1,9);
    insertAtHead(l1,9);
    insertAtHead(l1,9);
    insertAtHead(l1,9);
    insertAtHead(l1,9);
    insertAtHead(l1,9);
    insertAtHead(l1,9);

    insertAtHead(l2,9);
    insertAtHead(l2,9);
    insertAtHead(l2,9);
    insertAtHead(l2,9);

    ListNode* l3 = addTwoNumbers(l1,l2);
    printLL(l3);

    return 0;
}
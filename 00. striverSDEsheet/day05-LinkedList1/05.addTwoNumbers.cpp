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
void insertAtTail(ListNode* &head, ListNode* &tail, int d){
    if(head == NULL && tail == NULL){
        //first insertion 
        head =  new ListNode(d);
        tail = head;
        return;
    }
    ListNode* n = new ListNode(d);
    tail->next = n;
    tail = n;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    //iterate thorugh both the given linked lists 
    ListNode* ptr1 = l1;
    ListNode* ptr2 = l2;
    int carry = 0;
    while(ptr1!=NULL || ptr2!=NULL){
        int addValue;
        if(ptr1 == NULL){
            //only l2 is remaining
            addValue = carry + ptr2->val;
            insertAtTail(head, tail, addValue%10);
            carry = addValue/10;
            ptr2 = ptr2->next;
        }
        else if(ptr2 == NULL){
            //only l1 is remaining
            addValue = carry + ptr1->val;
            insertAtTail(head, tail, addValue%10);
            carry = addValue/10;
            ptr1 = ptr1->next;
        }
        else{
            //both linked lists are available
            addValue = carry + (ptr1->val + ptr2->val);
            insertAtTail(head, tail, addValue%10);
            carry = addValue/10;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    //now add the carry if it is greater than 0 
    if(carry > 0){
        insertAtTail(head, tail, carry);
    }
    return head;
}
int main(){

    return 0;
}
#include<iostream>
using namespace std;
bool isPalindrome(ListNode* head) {
    if(head->next == NULL)    return true;;
    //first lets find the mid point of the ll 
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* temp = head;
    int cnt = 0;
    while(fast!=NULL && fast->next != NULL){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
        cnt++;
    }
    cout<<temp->val<<endl;
    cout<<slow->val<<endl;

    //now we need to reverse the linked list starting from slow till end using prev, curr, next pointers
    ListNode* c = slow;
    ListNode* p = NULL;
    ListNode* n;

    while(c!=NULL){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    //now we will put the value of p, that is new head of reversed ll into temp->next 
    temp->next = p;

    //1->2->2->1 converted to 1->2>1->2
    //and 1->2->3->2->1 converted to 1->2>1->2->3
    //now keep one ptr at head, and other at slow..increment both for..
    //cnt number of times and check if values at both ptrs are same 

    ListNode* ptr1 = head;
    ListNode* ptr2 = temp->next;
    while(cnt--){
        if(ptr1->val != ptr2->val){
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}
int main()
{
    return 0;
}
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;

    int i = 0;
    //take fast pointer n steps ahead 
    while(i<n && fast != NULL){
        fast = fast->next;
        i++;
    }

    if(fast == NULL){
        //means we need to delete the first node 
        head = slow->next;
        delete slow;
        return head;
    }

    //now move both slow and fast pointers 1 step ahead
    ListNode * prev;
    while(fast != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}
int main(){

    return 0;
}
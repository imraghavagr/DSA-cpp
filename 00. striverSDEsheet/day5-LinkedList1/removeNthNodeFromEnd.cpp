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
    int cnt = 0;
    while(fast!=NULL && cnt<n){
        fast = fast->next;
        cnt++;
    }
    if(fast == NULL){
        //this means we need to delete the first node
        head = slow->next;
        return head;
    }
    //now take both slow and fast pointer 1 step ahead
    while(fast != NULL && fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next; 
    return head;
}
int main(){

    return 0;
}
//https://leetcode.com/problems/rotate-list/
#include<iostream>
using namespace std;

int findLengthLL(ListNode*  head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}
//brute force approach - time - O(k'n), n = len of ll and k' = k%n
//space - O(1)
//faster than just 5.25% submissions
ListNode* rotateRight1(ListNode* head, int k) {
    
    if(head == NULL)return NULL;
    int lenLL = findLengthLL(head);
    int actualK = k%lenLL;
    
    while(actualK>0){
        //every time first find the prev and tail pointer 
        ListNode* tail = head;
        ListNode* prev = head;
        while(tail->next != NULL){
            prev = tail;
            tail = tail->next;
        }
        prev->next = NULL;
        tail->next = head;
        head = tail;
        actualK--;
                
    }
    return head;
}
//better approach - just need to find the k'th node from the end.. that too k' = k%len 
//also, len of ll is found usng fast pointer in O(n/2) iterations
//time = O(n/2 + n) = O(n) and space = O(1)
int fastLengthLL(ListNode* head){
    ListNode* fast = head;
    int cnt = 0;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        cnt += 2;
    }
    if(fast == NULL)return cnt;
    else    return cnt+1;
}
ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL)return NULL;
    if(k == 0)return head;
    int len = fastLengthLL(head);
    int actualK = k%len;
    if(actualK == 0)return head;
    
    //now lets find the required pointers using slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* tail = head;
    ListNode* prev = head;
    
    //first take the fast pointer k steps ahead 
    for(int i = 0; i<actualK; i++){
        tail = fast;
        fast = fast->next;
    }
    //now take both slow and fast pointers one step ahead at a time
    while(fast!=NULL){
        prev = slow;
        slow = slow->next;
        tail = fast;
        fast = fast->next;
    }
    //now we have all the required pointers 
    tail->next = head;
    head = slow;
    prev->next = NULL;
    return head;
}

int main()
{   

    return 0;
}
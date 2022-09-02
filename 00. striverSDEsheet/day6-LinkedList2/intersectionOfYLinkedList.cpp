//https://leetcode.com/problems/intersection-of-two-linked-lists/
#include<iostream>
using namespace std;

//brute force - O(mn) - m = len of ll A, n = len of ll B
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
    //for every node in linked list A, traverse all nodes of linked list B 
    //and see if any node matches.
    ListNode* temp;
    while(headA != NULL){
        temp = headB;
        while(temp != NULL){
            if(headA == temp){
                return headA;
            }
            temp = temp->next;
        }
        headA = headA->next;
    }
    return NULL;
}
//optimal approach 
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
   
}
int main()
{
    return 0;
}
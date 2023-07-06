#include<iostream>
using namespace std;

//iterative way -> O(m+n) time O(1) space
ListNode* mergeLLIterative(ListNode* l1, ListNode* l2){
    ListNode* resHead = l1;
    ListNode* temp;
    while(l1 != NULL && l2 != NULL){
        //move l1 untill l1->val < l2->val 
        temp = NULL;
        while(l1 != NULL && l1->val <= l2->val){
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return resHead;
}
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL)  return l2;
    if(l2 == NULL)  return l1;
    //we will always point l1 to the smaller starting node val
    if(l1->val > l2->val)   swap(l1,l2);
    return mergeLLIterative(l1,l2);
}

//Recursive way -> O(m+n) time O(m+n) rec stack space
ListNode* merge(ListNode* &a, ListNode* &b){
    if(a == NULL)   return b;
    if(b == NULL)   return a;

    ListNode* c;
    if(a->val < b->val){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    return merge(list1, list2);
}
int main()
{
    return 0;
}
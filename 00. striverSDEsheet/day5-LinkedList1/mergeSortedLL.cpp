#include<iostream>
using namespace std;
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
#include<iostream>
using namespace std;
//using hashing 
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> st;
    while(head != NULL){
        if(st.find(head) != st.end())   return true;
        st.insert(head);
        head = head->next;
    }
    return false;
}

//using tortoise - hare approach (fast and slow pointer)
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)    return true;
    }
    return false;
}
int main()
{
    return 0;
}
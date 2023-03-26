//https://leetcode.com/problems/linked-list-cycle-ii/description/
#include<iostream>
using namespace std;
//Optimal Approach 
/*first detect a cycle:
    move slow pointer one step and fast pointer 2 steps 
    if fast reaches null, no cycle present return null
    else make slow = head, and now move both fast and slow pointer one step .. return the node where slow == fast
*/
//Time - O(N), space O(1)
ListNode *detectCycle(ListNode *head) {

    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
//Another approach - using hashing 
ListNode *detectCycle2(ListNode *head) {
    unordered_set<ListNode*> st;
    ListNode* temp = head;
    while(temp!=NULL){
        if(st.find(temp) != st.end()){
            return temp;
        }
        else{
            st.insert(temp);
        }
        temp = temp->next;
    }
    return NULL;
}
int main()
{
    return 0;
}
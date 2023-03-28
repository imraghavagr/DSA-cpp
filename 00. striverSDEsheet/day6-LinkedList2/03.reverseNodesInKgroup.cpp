#include<iostream>
using namespace std;
int findLenOfLL(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    int cnt = 0;
    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        cnt+=2;
    }
    if(fast != NULL)    return cnt+1;
    return cnt;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || k == 1)  return head;
    //find len of ll 
    int len = findLenOfLL(head);
    cout<<len<<endl;
    //lets make the dummy node and all other pointers
    ListNode* dummy = new ListNode(0);
    //point dummy to the head of the ll 
    dummy->next = head;
    //initially prev, curr and next will all point to dummy 
    ListNode *cur = dummy, *next = dummy, *prev = dummy;

    while(len >= k){
        cur = prev->next;
        next = cur->next;
        //now apply k-1 operations 
        for(int i = 1; i<k; i++){
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = cur->next;
        }
        prev = cur;
        len -= k;
    }
    return dummy->next;
}

int main()
{
    return 0;
}
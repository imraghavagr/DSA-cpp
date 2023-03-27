//https://leetcode.com/problems/rotate-list/
#include<iostream>
using namespace std;

//finding len and kth node from end can also be done using tortoise hare approach with better time complexity

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)  return head;
    int len = 1;
    ListNode* temp = head;
    while(temp->next != NULL){
        len++;
        temp = temp->next;
    }
    k = k%len;
    if(k == 0)  return head;
    //connect the last node to the first node
    temp->next = head;

    //now find the kth node from the end 
    int cnt = len-k;
    temp = head;
    ListNode* prev = head;
    while(cnt--){
        prev = temp;
        temp = temp->next; 
    }
    prev->next = NULL;
    head = temp;
    return head;
}

int main()
{   

    return 0;
}
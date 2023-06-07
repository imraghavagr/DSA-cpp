//https://leetcode.com/problems/intersection-of-two-linked-lists/
#include<iostream>
#include<unordered_set>
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
    //return null if there is no intersection point
    return NULL;
}

//approach 2: Using hashing
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> st;
    //traverse ll1 and store its addressed into set
    while(headA != NULL){
        st.insert(headA);
        headA = headA->next;
    }
    //now traverse ll2 and search if its current pointer is already present
    //in set.. if present it means it is the intersection point 
    while(headB != NULL){
        if(st.find(headB) != st.end()){
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}
//Approach 3 - using difference in len method
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //find len of ll A and ll B
    int lenA = 0, lenB = 0;
    while(headA != NULL || headB  != NULL){
        if(headA != NULL){
            lenA++;
            headA = headA->next;
        }
        if(headB != NULL){
            lenB++;
            headB = headB->next;
        }
    }
    
    int d = abs(lenA-lenB);
    ListNode* ptr1;
    ListNode* ptr2;
    if(lenA>lenB){
        ptr1 = headA;
        ptr2 = headB;
    }
    else{
        ptr1 = headB;
        ptr2 = headA;
    }
    //now take the ptr1 d steps ahead
    for(int i = 0; i<d; i++){
        ptr1 = ptr1->next;
    }
    //now take both ptr1 and ptr2 ahead, one step at a time
    while(ptr1 != NULL  && ptr2 != NULL){
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}
//approach 4 - extension of difference in len method 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* d1 = headA;
    ListNode* d2 = headB;
    while(true){
        if(d1 == d2){
            return d1;
        }
        d1 = d1->next;
        d2 = d2->next;
        if(d1 == NULL && d2 == NULL){
            return NULL;
        }
        if(d1 == NULL){
            d1 = headB;
        }
        else if(d2 == NULL){
            d2 = headA;
        }
    }
}
int main()
{
    return 0;
}
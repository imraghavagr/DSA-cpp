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
pair<int,int> findLength(ListNode* headA, ListNode* headB){
    int l1 = 0, l2 = 0; 
    while(headA != NULL || headB != NULL){
        if(headA != NULL){
            l1++; 
            headA = headA->next; 
        }
        if(headB != NULL){
            l2++; 
            headB = headB->next; 
        }
    }
    return {l1,l2};
}
void goAhead(ListNode* &head, int len){
    for(int i = 0; i<len; i++)  head = head -> next; 
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    pair<int,int> len = findLength(headA, headB);
    int lenDiff = abs(len.first - len.second);
    if(len.first > len.second){
        //take headA lenDiff steps ahead 
        goAhead(headA, lenDiff);
    }
    else if(len.second > len.first){
        //take headB lenDiff steps ahead 
        goAhead(headB, lenDiff);
    }
    //now take both ptrs 1 step ahead 
    while(headA != NULL){
        if(headA == headB){
            return headA; 
        }
        headA = headA->next; 
        headB = headB->next; 
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
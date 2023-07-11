//https://leetcode.com/problems/copy-list-with-random-pointer/description/
#include<iostream>
using namespace std;
//O(N) time .. O(N) space as we are using hashing other than the new linked list created
Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> mp;
    Node* temp = head;
    while(temp != NULL){
        Node* n = new Node(temp->val);
        mp[temp] = n;
        temp = temp->next;
    }
    //now connect the next and random pointers
    temp = head;
    while(temp != NULL){
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}
//optimal approach - without using extra space other than the new linked list created
Node* copyRandomList(Node* head) {
    if(head == NULL)    return head; 
    //step 1: create dummy nodes for every node 
    Node *temp = head; 
    Node* newNode;
    while(temp != NULL){
        newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode; 
        //update temp
        //since we have changed temp->next, we will go to the origal 
        //...next node via newNode created
        temp = temp->next->next;
    }
    //step2 : rearrange the random pointers 
    temp = head; 
    while(temp != NULL){
        if(temp->random != NULL)
            temp->next->random = temp->random->next; 
        temp = temp->next->next; 
    }

    //step3 : get the original linked list and the deep copy linked list 
    temp = head->next; 

    Node *ptr1 = head, *ptr2 = ptr1->next->next; 
    while(ptr2 != NULL){
        ptr1->next->next = ptr2->next; 
        ptr1->next = ptr2;
        ptr1 = ptr2; 
        ptr2 = ptr1->next->next; 
    }
    ptr1->next = NULL; 
    return temp; 
}
int main()
{
    return 0;
}
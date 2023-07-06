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

int main()
{
    return 0;
}
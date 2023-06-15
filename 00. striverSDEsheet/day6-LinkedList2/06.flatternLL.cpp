//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
#include<iostream>
using namespace std;
void mergeTwoSortedLL(Node* l1, Node* l2){
    //no need to perform this since main linked list is also in sorted order 
    // if(l1->data > l2->data)   swap(l1, l2);
    Node* temp;
    while(l1 != NULL && l2 != NULL){
        temp = NULL;
        while(l1 != NULL && l1->data <= l2->data){
            temp = l1;
            l1 = l1->bottom;
        }
        temp->bottom = l2;
        swap(l1,l2);
    }
}
Node *flatten(Node *root)
{
   if(root == NULL || root->next == NULL)   return root;
   
   Node* l1;
   Node* l2;
   
   Node* res = root;
   Node* dummy = root->next;
   root->next = NULL;
   while(dummy != NULL){
        l1 = res;
        l2 = dummy;
        dummy = l2->next;
        l2->next = NULL;
        mergeTwoSortedLL(l1,l2);   
   }
   return res;
}
int main()
{
    return 0;
}
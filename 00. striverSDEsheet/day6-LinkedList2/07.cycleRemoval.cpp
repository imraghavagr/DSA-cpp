#include<iostream>
using namespace std;
void removeLoop(Node* head)
{   
    //first find if the cycle exists or not 
    Node* slow = head;
    Node* fast = head;
    Node* prev;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            //this means that a cycle exists 
            //now take the slow pointer back to head, and again increase slow and fast 
            //one one step ahead 
            slow = head;
            while(slow!=fast){
                //earlier prev pointer slow ka peecha kar raha tha 
                //ab prev pointer fast ka peecha krega 
                //alag alag issliye kar rahe hai kyuki kai baar cycle ka 
                //start point head hii hoga ... dry run 
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }
            //now the slow ptr contains the begining point of the cycle 
            prev->next = NULL;
        }
    }
}
int main()
{
    return 0;
}
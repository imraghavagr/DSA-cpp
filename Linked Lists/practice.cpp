#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// head - Head pointer of the Linked List
// Return a boolean value indicating the presence of cycle
// If the cycle is present, modify the linked list to remove the cycle as well
bool breakCycle(Node*head){
    Node*fast = head;
    Node*slow = head;
    int flag = 0;
    int cycleExists = 0;
    while(fast!=NULL and fast->next != NULL){

        if(flag == 0){
            fast = fast->next->next;
            slow = slow->next;  
            
            if(fast == slow){
                //keep fast as it is and take slow back to the head of the ll
                cycleExists = 1;
                slow = head;
                flag = 1;
            }
            
        }
        if(flag == 1){
            //means fast and slow have met once, and rn , slow is in the begining and fast is at the last meeting point
            //now both fast and slow has to move one step at a time
            slow = slow->next;
            if(fast->next != slow){
                fast = fast->next;
            }
            fast->next = NULL;
        }
        
    }

    if(cycleExists == 1){
        return true;
    }
    else{
        return false;   
    }
}

/*
*
*
*   You do not need to refer or modify any code below this. 
*   Only modify the above function definition.
*   Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
*   You do not even need to read or know about the code below.
*
*
*
*/

void buildCycleList(Node *&head)
{
    unordered_map<int, Node *> hash;
    int x;
    cin >> x;
    if (x == -1)
    {
        head = NULL;
        return;
    }
    head = new Node(x);
    hash[x] = head;
    Node *current = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            current->next = hash[x];
            return;
        }
        Node *n = new Node(x);
        current->next = n;
        current = n;
        hash[x] = n;
    }
    current->next = NULL;
}

void printLinkedList(Node *head)
{
    unordered_set<int> s;
    while (head != NULL)
    {
        if (s.find(head->data) != s.end())
        {
            cout << "\nCycle detected at " << head->data;
            return;
        }
        cout << head->data << " ";
        s.insert(head->data);
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    buildCycleList(head);

    bool cyclePresent = breakCycle(head);
    if (cyclePresent)
    {
        cout << "Cycle was present\n";
    }
    else
    {
        cout << "No cycle\n";
    }

    cout << "Linked List - ";
    printLinkedList(head);

    return 0;
}
#include<iostream>
using namespace std;
/*
                    100          500          200          250
    head = 100      1|500  ->    2|200  ->    3|250  ->    4|NULL
    P               C             N
*/

class node{
public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};
void insertAtHead(node*&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = head;
    head = n;
}
void insertAtTail(node*&head, int d){
    //without mainting a tail
    if(head == NULL){
        
    }
    node* temp = head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    node* n = new node(d);
    temp -> next = n;
}

void reverseLL(node*&head){
  if(head == NULL or head->next == NULL){
      return;
  }
  node*p = NULL;
  node*c = head;
  node*n;
  while(c!= NULL){
      n = c->next;

      c->next = p;
      p = c;
      c = n;
  }
  head = p;
}
node* recReverse(node*head){
    //base case
    if(head == NULL or head->next == NULL){
        return head;
    }

    //rec case
    node* sHead = recReverse(head->next);

    node*temp = head->next;
    temp->next = head;
    head->next = NULL;

    return sHead;

}
int midPoint(node*head){
    if(head == NULL){
        return -1; //return -1 if the ll is empty.
    }
    node*slow = head;
    node*fast = head;
    while(fast->next != NULL and fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

node* solve(node* head, int n){
    
    node* slow = head;
    node* fast = head;
    node* prev;

    while(n--){
        fast = fast->next;
    }
    while(fast != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}
void printLL(node*head){
   
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    node* head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtTail(head,12);
    printLL(head);
    reverseLL(head);
    printLL(head);
    head = recReverse(head);
    printLL(head);
    return 0;
}
#include<iostream>
using namespace std;
class LRUCache {
public:
    class Node{
    public:
        int key,value;
        Node *prev, *next; 
        Node(int key, int value){
            this->key = key;
            this->value = value;
            prev = NULL, next = NULL;
        }
    };
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    int cap;
    unordered_map<int,Node*> mp; 

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail; 
        tail->prev = head; 
    }
    Node* insertAtHead(int key, int val){
        Node* n = new Node(key, val);
        n->prev = head; 
        n->next = head->next;
        head->next->prev = n;
        head->next = n; 
        return n;
    }
    void deleteNode(Node* node){
        node->prev->next = node->next; 
        node->next->prev = node->prev; 
    }
    int get(int key) {
        if(mp.find(key) == mp.end())    return -1; 
        Node* toDelete = mp[key];
        int val = toDelete->value;
        deleteNode(toDelete);
        Node* newAddress = insertAtHead(key, val);
        mp[key] = newAddress;
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            //means key is already present, we need to update it 
            Node* toDelete = mp[key];
            mp.erase(key);
            deleteNode(toDelete);
            Node* newAddress = insertAtHead(key, value);
            mp[key] = newAddress;
        }
        else{
            if(mp.size() == cap){
                //delete at tail 
                int k = tail->prev->key;
                deleteNode(tail->prev);
                mp.erase(k);
            }
            Node* newAddress = insertAtHead(key, value);
            mp[key] = newAddress;
        }
    }
};
int main()
{
    return 0;
}
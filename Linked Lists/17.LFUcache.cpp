#include<iostream>
using namespace std;
struct Node{
    int key, value, cnt;
    Node *prev, *next;
    Node(int k, int v){
        key = k, value = v; 
        prev = NULL, next = NULL;
        cnt = 0;
    }
};
class List{
public:
    Node *head, *tail;
    int size;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    Node* insertAtHead(int key, int val){
        Node* n = new Node(key, val);
        n->prev = head; 
        n->next = head->next;
        head->next->prev = n;
        head->next = n; 
        size++;
        return n;
    }
    void deleteNode(Node* node){
        node->prev->next = node->next; 
        node->next->prev = node->prev; 
        size--;
    }
};
class LFUCache {
    unordered_map<int,Node*> keyAddressMap;
    unordered_map<int,List*> freqListMap;
    int maxCapacity, leastFrequentFreq, currSize;
public:
    LFUCache(int capacity) {
        maxCapacity = capacity;
        leastFrequentFreq = 1;
        currSize = 0;
    }    
    void updateFreqListMap(Node* presentAddr, int freq, int key, int value){
        freqListMap[freq]->deleteNode(presentAddr);
        if(freq == leastFrequentFreq && freqListMap[freq]->size == 0){
            leastFrequentFreq ++;
        }
        List *nextHigherFreqList = new List();
        if(freqListMap.find(freq+1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[freq+1];
        }
        Node* newAddr = nextHigherFreqList->insertAtHead(key, value);
        newAddr->cnt = freq+1;
        keyAddressMap[key] = newAddr;
        freqListMap[newAddr->cnt] = nextHigherFreqList;        
    }
    int get(int key) {
        if(keyAddressMap.find(key) == keyAddressMap.end()){
            return -1;
        }
        else{
            Node* presentAddr = keyAddressMap[key];
            int freq = presentAddr->cnt;
            int value = presentAddr->value;
            updateFreqListMap(presentAddr, freq, key, value);
            return value;
        }
    }    
    void put(int key, int value) {
        if(keyAddressMap.find(key) != keyAddressMap.end()){
            //this means that this key is already present
            Node* presentAddr = keyAddressMap[key];
            int freq = presentAddr->cnt;
            updateFreqListMap(presentAddr, freq, key, value);
        }
        else{
            if(currSize == maxCapacity){
                Node* toDelete = freqListMap[leastFrequentFreq]->tail->prev;
                freqListMap[leastFrequentFreq]->deleteNode(toDelete);
                if(freqListMap[leastFrequentFreq]->size == 0){
                    leastFrequentFreq ++;
                }
                keyAddressMap.erase(toDelete->key);
                currSize--;
            }
            //this key,value is coming for the first time, so we will insert it into mp1[1]
            List *nextHigherFreqList = new List();
            if(freqListMap.find(1) != freqListMap.end()){
                nextHigherFreqList = freqListMap[1];
            }
            Node* newAddr = nextHigherFreqList->insertAtHead(key, value);
            newAddr->cnt = 1;
            freqListMap[1] = nextHigherFreqList;                    
            keyAddressMap[key] = newAddr;
            leastFrequentFreq = 1;
            currSize++;
        }
    }
};
int main()
{
    return 0;
}
// https://practice.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1
#include<iostream>
using namespace std;
struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i = 31; i>=0; i--){
            //insert all the 32 bits of num from left to right into the trie
            //extracting ith bit 
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMaximum(int x){
        int maxXor = 0;
        Node* node = root;
        for(int i = 31; i>=0; i--){
            //find the ith bit in x 
            int bit = (x>>i) & 1;
            if(node->containsKey(1-bit)){
                //turn on the ith bit in maxXor 
                maxXor = maxXor | (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxXor;
    }
};
int max_xor(int arr[] , int n)
{   
    Trie* node = new Trie();
    for(int i = 0; i<n; i++){
        //insert all elements(bits) into the trie 
        node->insert(arr[i]);
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = max(ans, node->getMaximum(arr[i]));
    }
    return ans;
}
int main()
{
    return 0;
}
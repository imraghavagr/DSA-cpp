//ip:
//arr = 9, 8, 7, 6, 5
//x = 8
//find arr[i] such that arr[i]^x is maximum 
#include<iostream>
#include<vector>
using namespace std;
struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit, Node* node){
        links[bit] = node;
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
            //insert all 32 bits of number num from left to right 
            //extract the ith bit 
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMaximum(int x){
        Node* node = root;
        int ans = 0;
        //form all 32 bits of the answer from left to right 
        for(int i = 31; i>=0; i--){
            //check the ith bit in x 
            int bit = (x>>i)&1;
            //now we need the !bit in the ans for xor to be maximised
            if(node->containsKey(1-bit)){
                //if desired bit is present 
                //turn on the ith bit in the answer 
                ans = ans | (1<<i);
                node = node->get(1-bit);
            }
            else{
                //we will not change the ith bit 
                node = node->get(bit);
            }
        }
        return ans;
    }
};
int maximumXor(vector<int> &arr, int x){
    Trie* node = new Trie();
    //first insert all the nums in arr into the trie 
    for(int x : arr){
        node->insert(x);
    }
    return node->getMaximum(x);
}
int main()
{   
    vector<int> arr = {9,8,7,5,4};
    int x = 8;
    cout<<maximumXor(arr, 8)<<endl;
    return 0;
}
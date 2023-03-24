#include<iostream>
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
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> ans(queries.size());
    vector<vector<int>> tempQueries; // {m,x,i}
    for(int i = 0; i<queries.size(); i++){
        tempQueries.push_back({queries[i][1], queries[i][0],i});
    }
    sort(nums.begin(), nums.end());
    sort(tempQueries.begin(), tempQueries.end());

    int j = 0;
    Trie* node = new Trie();
    for(auto it : tempQueries){
        int m = it[0];
        int x = it[1];
        int index = it[2];
        //insert all the nums <= m into the trie
        while(j<nums.size() && nums[j] <= m){
            node->insert(nums[j]);
            j++;
        }
        if(j == 0)  ans[index] = -1;
        else{
            ans[index] = node->getMaximum(x);
        }
    }
    return ans;
}
int main()
{
    return 0;
}
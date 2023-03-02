//https://practice.geeksforgeeks.org/problems/account-merge/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=account-merge
#include<iostream>
using namespace std;
class DisjointSet{
  public:
    vector<int> size, parent;
    DisjointSet(int n){
        //initially size of component of each node is 1
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findUltimateParent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ultParentU = findUltimateParent(u);
        int ultParentV = findUltimateParent(v);
        if(ultParentU == ultParentV){
            //both belong to same component, no need to do anything 
            return;
        }
        if(size[ultParentU] < size[ultParentV]){
            //u gets attached to v
            parent[ultParentU] = ultParentV;
            //also size of V increaes 
            size[ultParentV] += size[ultParentU];
        }
        else{
            parent[ultParentV] = ultParentU;
            size[ultParentU] += size[ultParentV];
        }
    }
};
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    // code here
    DisjointSet ds(accounts.size());
    unordered_map<string, int> mp;
    for(int i = 0; i<accounts.size(); i++){
        //now for every row, check for each email 
        for(int j = 1; j<accounts[i].size(); j++){
            if(mp.find(accounts[i][j]) == mp.end()){
                mp[accounts[i][j]] = i;
            }
            else{
                //if it is already present 
                //merge it with the existing key value node 
                ds.unionBySize(mp[accounts[i][j]], i);
            }
        }
    }
    unordered_map<int, vector<string>> mp2;
    //now once our disjoint set is ready, we will start merging 
    vector<vector<string>> ans;
    for(auto it : mp){
        string mail = it.first;
        int index = it.second;
        //merge the string 
        //add a name to its ultimate parent 
        int finalIndex = ds.findUltimateParent(index);
        mp2[finalIndex].push_back(mail);
    }
    for(auto it : mp2){
        int index = it.first;
        vector<string> mails =it.second;
        sort(mails.begin(), mails.end());
        mails.insert(mails.begin(), accounts[index][0]);
        ans.push_back(mails);
    }
    return ans;
}
int main()
{
    return 0;
}
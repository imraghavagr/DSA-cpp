//https://leetcode.com/problems/find-leaves-of-binary-tree/description/?envType=study-plan-v2&envId=premium-algo-100
#include<iostream>
using namespace std;
//approach 1 
int solve(TreeNode* root, map<int,vector<int>> &mp){
    if(root == NULL)    return 0; 
    int ls = solve(root->left, mp);
    int rs = solve(root->right, mp);
    int hRoot = max(ls,rs)+1;
    mp[hRoot].push_back(root->val);
    return hRoot;
}
vector<vector<int>> findLeaves(TreeNode* root) {
    //while doing postorder (as height calc), all the nodes having same height will be together 
    map<int,vector<int>> mp; 
    solve(root, mp);
    vector<vector<int>> ans; 
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans; 
}

//optimal
int solve(TreeNode* root, vector<vector<int>> &ans){
    if(root == NULL)    return -1; 
    int ls = solve(root->left, ans);
    int rs = solve(root->right, ans);
    int hRoot = max(ls,rs)+1;
    //now we need add root->val at ans[hRott] array 
    //ans[hRoot] may not exist 
    if(hRoot >= ans.size())    ans.push_back({});
    ans[hRoot].push_back(root->val);
    return hRoot;
}
vector<vector<int>> findLeaves(TreeNode* root) {
    //instead of saving it into map 
    //we can directly store it in our ans array. 
    vector<vector<int>> ans;
    solve(root, ans);        
    return ans; 
}
int main()
{
    return 0;
}
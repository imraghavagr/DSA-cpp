#include<iostream>
using namespace std;
//Approach 1 
TreeNode* solve(int ps, int pe, vector<int> &preorder, int is, int ie, vector<int> &inorder, unordered_map<int,int>&mp){
    if(ps > pe || is > ie)  return NULL; 
    TreeNode* root = new TreeNode(preorder[ps]);
    int idx = mp[preorder[ps]];
    int numsLeft = idx - is; 
    root->left = solve(ps+1, ps+numsLeft, preorder, is, idx-1, inorder, mp);
    root->right = solve(ps+numsLeft+1, pe, preorder, idx+1, ie, inorder, mp);
    return root; 
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<int> inorder(preorder);
    sort(inorder.begin(), inorder.end());
    int n = inorder.size();
    unordered_map<int,int> mp; 
    for(int i = 0; i<n; i++){
        mp[inorder[i]] = i; 
    }
    return solve(0,n-1,preorder,0,n-1,inorder, mp);
}
//optimal approach 
reeNode* solve(vector<int> &preorder, int high, int &i){
    
    if(i == preorder.size() || preorder[i] > high)  return NULL;
    
    TreeNode* root = new TreeNode(preorder[i++]);

    root->left = solve(preorder, root->val, i);
    root->right = solve(preorder, high, i);

    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    int high = INT_MAX;
    return solve(preorder, high, i);
}
int main()
{
    return 0;
}
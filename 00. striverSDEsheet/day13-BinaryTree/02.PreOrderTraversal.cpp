#include<iostream>
using namespace std;
//Recursive
void solve(TreeNode* root, vector<int> &ans){
    if(root == NULL)    return;
    ////root, left, right
    ans.push_back(root->val);
    solve(root->left, ans);
    solve(root->right, ans);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans; 
    solve(root, ans);
    return ans;
}

/*
Iterative
Algo:
push the root node into the stk. 
    now print stk.top()
    insert right and then left child 
*/
vector<int> preorderTraversal(TreeNode* root) {
    if(root == NULL)    return {};
    vector<int> ans; 
    stack<TreeNode*> stk; 
    stk.push(root);
    while(!stk.empty()){
        auto node = stk.top();  stk.pop();
        ans.push_back(node->val);
        if(node->right) stk.push(node->right);
        if(node->left)   stk.push(node->left);
    }
    return ans;
}
int main()
{
    return 0;
}
#include<iostream>
using namespace std;
//recursive
oid postorder(TreeNode* root, vector<int> &ans){
    if(root == NULL)    return; 
    //left, right, root 
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    postorder(root, ans);
    return ans; 
}
//iterative -> O(2N) space
vector<int> postorderTraversal(TreeNode* root) {
    if(root == NULL)    return {};
    vector<int> ans; 
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        auto node = stk.top();  stk.pop(); 
        ans.push_back(node->val);
        if(node->left)  stk.push(node->left);
        if(node->right) stk.push(node->right);
    }
    reverse(ans.begin(), ans.end());
    return ans; 
}
//iterative -> O(1) space 
int main()
{
    return 0;
}
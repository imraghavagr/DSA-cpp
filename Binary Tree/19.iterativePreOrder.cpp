#include<iostream>
using namespace std;
//pre order-> root, left, right
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL)    return ans;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* node =  stk.top();
        stk.pop();
        ans.push_back(node->val);
        //we will push in reverse order into the stack
        if(node->right != NULL) stk.push(node->right);
        if(node->left != NULL) stk.push(node->left);
    }
    return ans;
}
int main()
{
    return 0;
}
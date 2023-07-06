#include<iostream>
using namespace std;
//recursive 
void inorder(TreeNode* root, vector<int> &ans){
    if(root == NULL)    return;
    //left, root, right 
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans; 
    inorder(root, ans);
    return ans;
}

//iterative
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk; 
    vector<int> ans; 
    TreeNode* node = root; 
    while(true){
        if(node != NULL){
            stk.push(node);
            node = node->left;
        }
        else{
            if(stk.empty()) break;
            node = stk.top(); stk.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
    return ans;
}
int main()
{
    return 0;
}
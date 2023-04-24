#include<iostream>
using namespace std;
//traverse the tree starting from root 
//keep on pushing root->left into the stack untill it is not null 
//once root->left is null .. push the current root into the ans .. then 
//keep on pushing root->right into the stack .. 
//traverse the tree starting from root 
//keep on pushing root->left into the stack untill it is not null 
//once root->left is null .. push the current root into the ans .. then 
//keep on pushing root->right into the stack .. 
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    stack<TreeNode*> stk; 

    TreeNode* node = root;        
    while(true){
        if(node != NULL){
            //push it into the stk and go further left 
            stk.push(node);
            node = node->left;
        }
        else{
            if(stk.empty()) break;
            node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            //now go right 
            node = node->right;
        }
    }
    return ans;
}
int main()
{
    return 0;
}
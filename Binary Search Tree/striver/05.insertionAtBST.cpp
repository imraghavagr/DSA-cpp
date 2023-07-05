#include<iostream>
using namespace std;
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL)    return new TreeNode(val);
    
    if(val > root->val){
        root->right = insertIntoBST(root->right, val);
    }
    else    root->left = insertIntoBST(root->left,val);
    return root;
}
//iterative method - O(H) time, O(1) space 
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL)    return new TreeNode(val);
    TreeNode* prev = NULL; 
    TreeNode* curr = root; 
    while(curr != NULL){
        prev = curr; 
        if(val > curr->val){                
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    if(prev->val < val){
        prev->right = new TreeNode(val);
    }
    else{
        prev->left = new TreeNode(val);
    }
    return root; 
}
int main()
{
    return 0;
}
//https://leetcode.com/problems/search-in-a-binary-search-tree/description/
#include<iostream>
using namespace std;
//recursive soln - O(H) time, O(H) space 
TreeNode* search(TreeNode* root, int val){
    if(root == NULL || root->val == val)    return root;
    return root->val > val ?  search(root->left, val): search(root->right, val);
}
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL)    return NULL;
    return search(root, val);
}
//Iterative soln -> O(H) time, O(1) space 
TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* curr = root; 
    while(curr != NULL){
        if(curr->val == val)    return curr; 
        else if(val > curr->val){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return NULL; 
}
int main()
{
    return 0;
}
//https://leetcode.com/problems/search-in-a-binary-search-tree/description/
#include<iostream>
using namespace std;
TreeNode* search(TreeNode* root, int val){
    if(root == NULL || root->val == val)    return root;
    return root->val > val ?  search(root->left, val): search(root->right, val);
}
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL)    return NULL;
    return search(root, val);
}
int main()
{
    return 0;
}
#include<iostream>
using namespace std;
TreeNode* findRightMostNode(TreeNode* root){
    TreeNode* curr = root; 
    while(curr->right != NULL){
        curr = curr->right;
    }
    return curr; 
}
TreeNode* deleteAtRoot(TreeNode* root){
    if(root->left == NULL && root->right == NULL)   return NULL; 
    TreeNode* nodeLeft = root->left; 
    TreeNode* nodeRight = root->right; 
    if(root->left == NULL){
        delete root;
        return nodeRight;
    }
    else if(root->right == NULL){
        delete root; 
        return nodeLeft;
    }
    else{
        //we have both left and right children for the root 
        TreeNode* rightMostNode = findRightMostNode(root->left);
        rightMostNode->right = root->right;
        delete root; 
        return nodeLeft;
    }        
}
TreeNode* searchAndDelete(TreeNode* originalRoot, TreeNode* root, int key){
    if(root == NULL)    return originalRoot;
    if(root->right != NULL && root->right->val == key){
        root->right = deleteAtRoot(root->right);
        return originalRoot;
    }
    else if(root->left != NULL && root->left->val == key){
        root->left = deleteAtRoot(root->left);
        return originalRoot;
    }
    else if(root->val > key){
        return searchAndDelete(originalRoot, root->left, key);
    }
    else{
        return searchAndDelete(originalRoot, root->right, key);
    }
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL)    return NULL;
    if(root->val == key){
        return deleteAtRoot(root);
    }
    return searchAndDelete(root,root,key);
}
int main()
{
    return 0;
}
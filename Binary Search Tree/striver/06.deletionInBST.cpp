#include<iostream>
using namespace std;
TreeNode* deleteAtNode(TreeNode* node){
    if(node->left == NULL && node->right == NULL)   return NULL;
    if(node->left == NULL){
        return node->right;
    }
    else if(node->right == NULL)    return node->left;

    TreeNode* rightMostNode = findRightMostNode(node->left);

    rightMostNode->right = node->right;
    return node->left;
}
TreeNode* findRightMostNode(TreeNode* node){

    if(node->right == NULL) return node;

    return findRightMostNode(node->right);

}
TreeNode* searchAndDelete(TreeNode* originalRoot, TreeNode* root, int key){
    if(root == NULL)    return originalRoot;
    if(root->left != NULL && root->left->val == key){
        root->left = deleteAtNode(root->left);
        return originalRoot;
    }
    else if(root->right != NULL && root->right->val == key){
        root->right = deleteAtNode(root->right);
        return originalRoot;
    }
    else if(key > root->val)    return searchAndDelete(originalRoot, root->right, key);
    else   return searchAndDelete(originalRoot, root->left, key);

}
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return root;
    if(root->val == key){
        return deleteAtNode(root);
    }
    return searchAndDelete(root, root, key);
}
int main()
{
    return 0;
}
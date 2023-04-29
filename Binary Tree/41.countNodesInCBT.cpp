#include<iostream>
using namespace std;
//T -> O(logN^2) approach
//S -> O(logN)

int solve(TreeNode* root){
    if(root == NULL)    return 0;
    
    //LogN time 
    int lh = findLeftSubTreeHeight(root);
    int rh = findRightSubTreeHeight(root);

    if(lh == rh){
        //means this is a perfre binary tree 
        return (1<<lh)-1;
    }

    return 1 + solve(root->left) + solve(root->right);
}
int findLeftSubTreeHeight(TreeNode* root){
    int height = 0;
    while(root != NULL){
        root = root->left;
        height++;
    }
    return height;
}
int findRightSubTreeHeight(TreeNode* root){
    int height = 0;
    while(root != NULL){
        root = root->right;
        height++;
    }
    return height;
}
int countNodes(TreeNode* root) {
    return solve(root);
}
int main()
{
    return 0;
}
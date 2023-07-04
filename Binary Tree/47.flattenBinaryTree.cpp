#include<iostream>
using namespace std;
//Approach 1 => Recursive solution:
//             1. do right left root traversal
//             2. For curr node, update curr->right = prev; curr->left = NULL; 
//             3. Update prev = curr;
TreeNode* prev = NULL; 
void solve(TreeNode* root){
    if(root == NULL)    return;

    //right 
    solve(root->right);
    //left
    solve(root->left);
    //root
    //connect the curr node's right to the prev node 
    root->right = prev;
    //connect curr node's left to null 
    root->left = NULL;
    //update prev to curr node 
    prev = root; 
}
void flatten(TreeNode* root) {
    if(root == NULL)    return;
    solve(root);
}
int main()
{
    return 0;
}
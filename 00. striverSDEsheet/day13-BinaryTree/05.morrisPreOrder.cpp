#include<iostream>
using namespace std;
vector<int> preorderTraversal(TreeNode* root) {
    if(root == NULL)    return {};
    vector<int> preorder; 
    TreeNode* curr = root; 
    while(curr  != NULL){
        //when the ls does not exist
        if(curr->left == NULL){
            preorder.push_back(curr->val);
            //now go right
            curr = curr->right;
        }
        else{
            //go to the right most node in the ls of the curr node
            TreeNode* prev = curr->left; 
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                //thread is not made, make thread, print curr, and then move left 
                preorder.push_back(curr->val);
                prev->right = curr; 
                curr = curr->left;
            }
            else{
                //thread is already made => left traversal is already done..
                //break thread, move right 
                prev->right = NULL; 
                curr = curr->right; 
            }
        }
    }
    return preorder;
}
int main()
{
    return 0;
}
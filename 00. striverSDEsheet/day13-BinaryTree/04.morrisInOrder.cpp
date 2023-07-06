#include<iostream>
using namespace std;
vector<int> inorderTraversal(TreeNode* root) {
    if(root == NULL)    return {};
    vector<int> inorder; 
    TreeNode* curr = root; 

    while(curr != NULL){
        //if there is not left node of the curr node
        if(curr->left == NULL){
            inorder.push_back(curr->val);
            //go right 
            curr = curr->right;
        }
        else{
            //there exists a left subtree 
            //find the rightmost node in the left subtree of curr node 
            TreeNode* prev = curr->left; 
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == curr){
                //this means the thread is already made and the left traversal is already done 
                inorder.push_back(curr->val);
                //remove its connection/thread to curr node 
                prev->right = NULL;
                //left side is traversed, go right 
                curr = curr->right; 
            }
            else{
                //left part is yet to be traversed 
                //make the connection first 
                prev->right = curr; 
                curr = curr->left;
            }
        }
    }    
    return inorder;    
}
int main()
{
    return 0;
}
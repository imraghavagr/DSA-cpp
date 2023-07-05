#include<iostream>
using namespace std;
TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL)    return NULL;
    if(p == root || q == root)  return root;
    else if(p->val < root->val && q->val < root->val){
        return solve(root->left, p, q);
    }
    else if(p->val > root->val && q->val > root->val){
        return solve(root->right, p, q);
    }
    else{
        return root;
    }
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return solve(root, p, q);
}
//iterative soln 
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* curr = root; 
    while(curr != NULL){
        if(curr->val < p->val && curr->val < q->val){
            curr = curr->right;
        }
        else if(curr->val > p->val && curr->val > q->val){
            curr = curr->left; 
        }
        else{
            return curr; 
        }
    }
    return NULL; 
}
int main()
{
    return 0;
}
#include<iostream>
using namespace std;
bool solve(TreeNode* t1, TreeNode* t2){
    if(t1 == NULL && t2 == NULL) return true;
    if(t1 == NULL || t2 == NULL)    return false;

    return (t1->val == t2->val) && solve(t1->left, t2->right) && solve(t1->right, t2->left);
}
bool isSymmetric(TreeNode* root) {
    return solve(root->left, root->right);
}
int main()
{
    return 0;
}
//https://leetcode.com/problems/binary-tree-maximum-path-sum/
#include<iostream>
using namespace std;
int res = INT_MIN;
int solve(TreeNode* root){
    if(root == NULL)    return 0;
    int ls = max(0,solve(root->left));
    int rs = max(0, solve(root->right));
    res = max(res, root->val+ls+rs);
    return root->val+max(ls, rs);
}
int maxPathSum(TreeNode* root) {
    solve(root);
    return res;
}
int main()
{
    return 0;
}
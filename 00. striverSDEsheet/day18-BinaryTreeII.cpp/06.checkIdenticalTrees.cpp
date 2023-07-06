//https://leetcode.com/problems/same-tree/
#include<iostream>
using namespace std;
bool solve(TreeNode* p, TreeNode* q){
    if(p == NULL || q == NULL)  return p == q;

    //root, left, right 
    return (p->val == q->val) && solve(p->left, q->left) && solve(p->right, q->right);
}
bool isSameTree(TreeNode* p, TreeNode* q) {
    return solve(p,q);
}
int main()
{
    return 0;
}
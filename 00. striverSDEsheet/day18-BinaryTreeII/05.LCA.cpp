#include<iostream>
using namespace std;
TreeNode* solve(TreeNode* node, TreeNode* a, TreeNode* b){
    if(node == NULL)    return NULL;
    
    if(node == a || node == b)  return node;

    auto ls = solve(node->left, a, b);
    auto rs = solve(node->right, a, b);

    if(ls == NULL && rs == NULL)    return NULL;        
    else if(ls == NULL)  return rs;
    else if(rs == NULL) return ls;
    else    return node;        
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL)    return NULL;
    return solve(root, p, q);
}
int main()
{
    return 0;
}
#include<iostream>
using namespace std;
reeNode* solve(vector<int> &preorder, int high, int &i){
    
    if(i == preorder.size() || preorder[i] > high)  return NULL;
    
    TreeNode* root = new TreeNode(preorder[i++]);

    root->left = solve(preorder, root->val, i);
    root->right = solve(preorder, high, i);

    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    int high = INT_MAX;
    return solve(preorder, high, i);
}
int main()
{
    return 0;
}
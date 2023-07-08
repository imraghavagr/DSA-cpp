//https://leetcode.com/problems/largest-bst-subtree/
#include<iostream>
using namespace std;
bool isLeaf(TreeNode* root){
    if(root->left == NULL && root->right == NULL)   return true;
    else    return false;
}
vector<int> solve(TreeNode* root){
    vector<int> v(3);
    if(root == NULL){s
        v[0] = 0;
        v[1] = INT_MIN;
        v[2] = INT_MAX;
        return v;
    }
    if(isLeaf(root)){
        v[0] = 1;
        v[1] = root->val;
        v[2] = root->val;
        return v;
    }
    vector<int> ls = solve(root->left);
    vector<int> rs = solve(root->right);

    if(root->val > ls[1] && root->val < rs[2]){
        int maxReturn = max(root->val, max(ls[1], rs[1]));
        int minReturn = min(root->val, min(ls[2], rs[2]));
        return {ls[0]+rs[0]+1, maxReturn, minReturn};
    }
    else{
        return {max(ls[0], rs[0]), INT_MAX, INT_MIN};
    }
}
int largestBSTSubtree(TreeNode* root) {
    return solve(root)[0];
}
int main()
{
    return 0;
}
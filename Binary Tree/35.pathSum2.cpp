//https://leetcode.com/problems/path-sum-ii/description/
#include<iostream>
using namespace std;
bool isLeaf(TreeNode* node){
    if(node->left == NULL && node->right == NULL)   return true;
    else    return false;
}
void findAllPaths(TreeNode* root, int targetSum, vector<int> &op,
vector<vector<int>> &ans, int currSum){

    if(root == NULL)    return;
    
    op.push_back(root->val);
    currSum += root->val;

    if(isLeaf(root) && currSum == targetSum)    ans.push_back(op);

    findAllPaths(root->left, targetSum, op, ans, currSum);
    findAllPaths(root->right, targetSum, op, ans, currSum);

    op.pop_back();
    currSum -= root->val;
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if(root == NULL)    return {};
    if(isLeaf(root) && root->val == targetSum)  return {{root->val}};
    vector<vector<int>> ans;
    vector<int> op;
    int currSum = 0;
    findAllPaths(root, targetSum, op, ans, currSum);
    return ans;
}
int main()
{
    return 0;
}
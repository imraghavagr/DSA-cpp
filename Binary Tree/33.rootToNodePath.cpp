//https://www.interviewbit.com/problems/path-to-given-node/
#include<iostream>
using namespace std;
bool preOrderTraversal(TreeNode* node, int B, vector<int>& ans){
    if(node == NULL)   return false;
    
    //root, left, right 
    ans.push_back(node->val);
    
    if(node->val == B)  return true;
    
    if(preOrderTraversal(node->left, B, ans) || preOrderTraversal(node->right, B, ans))
        return true;
    
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    if(A->val == B) return {B};    
    vector<int> ans;    
    bool dummy = preOrderTraversal(A, B, ans);
    return ans;
}
int main()
{
    return 0;
}
//zig-zag/spiral traverasal of a binary tree
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
#include<iostream>
using namespace std;
void solve(TreeNode* root, vector<vector<int>> &ans){
    if(root == NULL)    return;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);
        for(int i = 0; i<size; i++){
            auto node = q.front();
            q.pop();
            int index = leftToRight ?  i : size-1-i;
            temp[index] = node->val;
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(temp);
    }
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    solve(root, ans);
    return ans;
}
int main()
{
    return 0;
}
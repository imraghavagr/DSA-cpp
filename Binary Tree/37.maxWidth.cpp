#include<iostream>
using namespace std;
int solve(TreeNode* root){
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    long long maxWidth = 0;
    while(!q.empty()){
        int sz = q.size();
        long long firstIndex, lastIndex, width;
        long long mmin = q.front().second; // we will substract this from every index to avoid overflow 
        for(int idx = 0; idx<sz; idx++){
            auto it = q.front();
            q.pop();
            auto node = it.first;
            long long i = it.second - mmin;;
            if(idx == 0)  firstIndex = i;
            if(idx == sz-1)   lastIndex = i;
            if(node->left)  q.push({node->left, (2*i)+1});
            if(node->right)  q.push({node->right, (2*i)+2});
        }
        width = (lastIndex-firstIndex) + 1;
        maxWidth = max(maxWidth, width);
    }
    return maxWidth;
}
int widthOfBinaryTree(TreeNode* root) {
    if(root == NULL)    return 0;
    return solve(root);
}
int main()
{
    return 0;
}
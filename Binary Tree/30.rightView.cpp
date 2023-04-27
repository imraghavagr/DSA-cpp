#include<iostream>
using namespace std;
//Approach 1 -> Iterative way - BFS
void solve(TreeNode* root, vector<int> &ans){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        int rightMostVal; 
        for(int i = 0; i<sz; i++){
            auto it = q.front();
            q.pop();
            rightMostVal = it->val;
            if(it->left)    q.push(it->left);
            if(it->right)    q.push(it->right);
        }
        ans.push_back(rightMostVal);
    }
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == NULL)    return ans;
    solve(root, ans);
    return ans;
}
//Approach 2 -> recursive way 
void reversePreOrder(TreeNode* root, int level, vector<int> &ans){
    if(root == NULL)    return;

    //root, right, left 
    if(ans.size() == level) ans.push_back(root->val);
    reversePreOrder(root->right, level+1, ans);
    reversePreOrder(root->left, level+1, ans);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    reversePreOrder(root, 0, ans);
    return ans;
}
int main()
{
    return 0;
}
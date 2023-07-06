#include<iostream>
using namespace std;
vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == NULL)    return {};
    vector<vector<int>> ans; 
    queue<TreeNode*> q; 
    q.push(root);
    while(!q.empty()){
        int sz = q.size(); 
        vector<int> temp;
        for(int i = 0; i<sz; i++){
            TreeNode* node = q.front();     q.pop(); 
            temp.push_back(node->val);
            //push the left and the right child if they exist 
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    return 0;
}
#include<iostream>
using namespace std;
//recursive
int findHeight(TreeNode* root){
    if(root == NULL)    return 0;
    return max(findHeight(root->left), findHeight(root->right))+1;
}
int maxDepth(TreeNode* root) {
    return findHeight(root);
}

//iterative - just do bfs
int maxDepth(TreeNode* root) {
    if(root == NULL)    return 0;
    queue<TreeNode*> q; 
    q.push(root);
    int height = 0; 
    while(!q.empty()){
        int sz = q.size(); 
        height++;
        for(int i = 0; i<sz; i++){
            auto node = q.front();  q.pop(); 
            if(node->left)  q.push(node->left);
            if(node->right)  q.push(node->right);
        }
    }
    return height;
}
int main()
{
    return 0;
}
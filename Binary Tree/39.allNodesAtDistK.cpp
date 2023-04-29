#include<iostream>
using namespace std;
void findParentPtrs(unordered_map<TreeNode*, TreeNode*> &parentPtr, TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    parentPtr[root] = NULL;
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        if(node->left){
            parentPtr[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            parentPtr[node->right] = node;
            q.push(node->right);
        }
    }
}
void findNodesAtDistK(TreeNode* target, unordered_map<TreeNode*, TreeNode*> &parentPtr,
    int k, vector<int> &ans){  

    unordered_map<TreeNode*, bool> visArr;
    queue<TreeNode*> q;
    q.push(target);
    visArr[target] = true;
    int dist = 0;
    while(!q.empty()){
        if(dist++ == k)   break;
        int sz = q.size();
        for(int i = 0; i<sz; i++){
            auto node = q.front();
            q.pop();
            //current node se three directions me jaenge 
            if(node->left && !visArr[node->left]){
                q.push(node->left);
                visArr[node->left] = true;
            }
            if(node->right && !visArr[node->right]){
                q.push(node->right);
                visArr[node->right] = true;
            }
            if(parentPtr[node] && !visArr[parentPtr[node]]){
                q.push(parentPtr[node]);
                visArr[parentPtr[node]] = true;
            }
        }
    }
    while(!q.empty()){
        ans.push_back(q.front()->val);
        q.pop();
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans; 
    if(root == NULL)    return ans;
    //first lets get the parents pointer 
    unordered_map<TreeNode*, TreeNode*> parentPtr;
    findParentPtrs(parentPtr, root);
    findNodesAtDistK(target, parentPtr, k, ans);
    return ans;
}
int main()
{
    return 0;
}
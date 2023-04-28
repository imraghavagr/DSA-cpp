//find paths from root to all leaf nodes 
//https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths
#include<iostream>
using namespace std;
bool isLeaf(Node* node){
     if(node->left == NULL && node->right == NULL)  return true;
     else   return false;
 }
void solve(Node* node, vector<int> &op, vector<vector<int>> &ans){
    if(node == NULL)    return;
    
    op.push_back(node->data);
    //root 
    if(isLeaf(node)){
        ans.push_back(op);
    }
    
    solve(node->left, op, ans);
    solve(node->right, op, ans);
    
    op.pop_back();
}
vector<vector<int>> Paths(Node* root)
{
    if(isLeaf(root))    return {{root->data}};
    
    vector<vector<int>> ans;
    vector<int> op;
    solve(root, op, ans);
    return ans;
}
int main()
{
    return 0;
}
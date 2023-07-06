#include<iostream>
using namespace std;
pair<bool,int> solve(TreeNode* root){
    //we will do post order traversal 
    if(root == NULL){
        return {true, 0};
    }
    auto ls = solve(root->left);
    auto rs = solve(root->right);
    //for the tree to be hbt, the height difference between ls and rs must be <= 1
    pair<bool, int> p;
    p.second = max(ls.second, rs.second)+1;
    if(ls.first && rs.first && abs(ls.second - rs.second) <= 1){
        p.first = true;
    }
    else    p.first = false;
    return p; 
}
bool isBalanced(TreeNode* root) {
    pair<bool, int> p =  solve(root);
    return p.first; 
}
int main()
{
    return 0;
}
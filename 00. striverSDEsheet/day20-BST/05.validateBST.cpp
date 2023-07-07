#include<iostream>
using namespace std;
bool checkTree(TreeNode* root, long long low, long long high){
    if(root == NULL) return true;

    if(!(root->val > low && root->val < high)){
        //no nee to further check ..
        return false;
    }
    
    return checkTree(root->left, low, root->val) && 
            checkTree(root->right, root->val, high);
}
bool isValidBST(TreeNode* root) {
    if(root->left == NULL && root->right == NULL)   return true;
    long long low = LONG_MIN;
    long long high = LONG_MAX;
    return checkTree(root, low, high);
}
int main()
{
    return 0;
}
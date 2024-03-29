//we need to construct a height balanced bst 
//from a given sorted array 
#include<iostream>
using namespace std;
TreeNode* solve(vector<int> &nums, int s, int e){
    if(s>e){
        return NULL; 
    }
    int mid = s + (e-s)/2; 
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = solve(nums, s, mid-1); 
    root->right = solve(nums, mid+1, e); 
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return solve(nums, 0, nums.size()-1);
}
int main()
{
    return 0;
}
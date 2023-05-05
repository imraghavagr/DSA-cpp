#include<iostream>
using namespace std;
vector<int> solve(TreeNode* root, int &ans){
    if(root == NULL)    return {0, INT_MIN, INT_MAX};
    if(root->left == NULL && root->right == NULL)
        return {root->val, root->val, root->val};

    vector<int> ls = solve(root->left, ans);
    vector<int> rs = solve(root->right, ans);


    if(root->val > ls[1] && root->val < rs[2]){
        int maxReturn = max(root->val, max(ls[1], rs[1]));
        int minReturn = min(root->val, min(ls[2], rs[2]));
        int sum = root->val + ls[0] + rs[0];
        ans = max(ans, sum);
        // if(sum < 0) sum = max(ls[0], rs[0]);
        return {sum, maxReturn, minReturn};
    }
    else{
        int sum = max(ls[0], rs[0]);
        ans = max(ans, sum);
        return {sum, INT_MAX, INT_MIN};
    }
}
int maxSumBST(TreeNode* root) {
    int ans = 0;
    auto dummy = solve(root, ans);
    return ans;
}
int main()
{
    return 0;
}
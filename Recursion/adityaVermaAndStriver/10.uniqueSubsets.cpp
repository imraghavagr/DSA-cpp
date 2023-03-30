//https://leetcode.com/problems/subsets/description/
#include<iostream>
using namespace std;
//if there are no duplicates present in the given array
//then we do not need to sort the array.. also we do not need to use set
void solve(int i, vector<int> &nums, vector<int> &op, vector<vector<int>> &ans){
    if(i == nums.size()){
        ans.push_back(op);
        return;
    }
    op.push_back(nums[i]);
    solve(i+1, nums, op, ans);
    op.pop_back();
    solve(i+1, nums, op, ans);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> op;
    solve(0, nums,op, ans);
    return ans;
}

int main()
{
    return 0;
}
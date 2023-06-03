#include<iostream>
using namespace std;
//recursion + memoization 
int solve(int i, int prev, vector<int>& nums, vector<vector<int>> &dp){
    if(i == nums.size())    return 0;
    if(dp[i][prev+1] != -1) return dp[i][prev+1];
    if(prev == -1 || nums[i] > nums[prev]){
        return dp[i][prev+1] = max(1+solve(i+1, i, nums, dp), solve(i+1, prev, nums, dp));
    }
    else{
        return dp[i][prev+1] = solve(i+1, prev, nums, dp);
    }
}
int lengthOfLIS(vector<int>& nums) {
    vector<vector<int>> dp (nums.size(), vector<int>(nums.size()+1, -1));
    //since we cannot store at dp[i][-1].. we will do a cordinate shift, and store whatever dp[i][-1] had to store into dp[i][0] 
    return solve(0,-1, nums,dp);
}
int main()
{
    return 0;
}
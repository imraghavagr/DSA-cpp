#include<iostream>
using namespace std;
int solve(int idx, int start, vector<int> &nums, int *dp){
    if(idx < start) return 0; 
    if(idx == start)    return nums[idx];
    if(dp[idx] != -1)   return dp[idx];
    //now we can either rob the current house or not rob it         
    int rob = nums[idx] + solve(idx-2, start, nums, dp);
    int notRob = solve(idx-1,start, nums, dp);

    return dp[idx] = max(rob, notRob);
}
int rob(vector<int>& nums) {
    int n = nums.size(); 
    if(n == 1)  return nums[0];
    int dp[n];
    memset(dp, -1, sizeof(dp));
    int c1 = solve(n-1, 1, nums, dp);
    memset(dp, -1, sizeof(dp));
    int c2 = solve(n-2, 0, nums, dp);
    return max(c1,c2);
}
int main()
{
    return 0;
}
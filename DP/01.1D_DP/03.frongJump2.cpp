//https://practice.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost
#include<iostream>
using namespace std;
//memoized approach 
int solve(int ind, vector<int> &height, int k, vector<int> &dp){
    if(ind == 0)    return 0;
    if(dp[ind] != -1)   return dp[ind];
    //take k jumps 
    int minCost = INT_MAX;
    for(int i = 1; i<=k; i++){
        if(ind-i >= 0){
            int jump = abs(height[ind] - height[ind-i]) + solve(ind-i, height, k, dp);
            minCost = min(minCost, jump);
        }
    }
    return dp[ind] = minCost;
}
int minimizeCost(vector<int>& height, int n, int k) {
    vector<int> dp(n, -1);
    return solve(n-1, height, k, dp);
}
//tabular approach 
int solve(vector<int> &height, int k){
    int n = height.size();
    vector<int> dp(n, 0);
    //take k jumps 
    for(int ind = 1; ind<height.size(); ind++){
        int minCost = INT_MAX;
        for(int i = 1; i<=k; i++){
            if(ind-i >= 0){
                int jump = abs(height[ind] - height[ind-i]) + dp[ind-i];
                minCost = min(minCost, jump);
            }
        }
        dp[ind] = minCost;   
    }
    return dp[n-1];
}
int minimizeCost(vector<int>& height, int n, int k) {
    return solve(height, k);
}
int main()
{
    return 0;
}
//https://leetcode.com/problems/climbing-stairs/description/
#include<iostream>
using namespace std;

//memoized approach
int solve1(int n, vector<int> &dp){
    if(n == 0 ||  n == 1)    return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = solve(n-1, dp)+solve(n-2, dp);
}
//tabular approach 
int solve2(int n){
    vector<int> dp(n+1, -1);
    dp[0] = dp[1] = 1;
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
//space optimized approach 
int solve3(int n){
        int prev1 = 1;
        int prev2 = 1;
        int curr;
        for(int i = 2; i<=n; i++){
            curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
int climbStairs(int n) {
    //same as fibonacci number - we need to return f(n);
    return solve(n);
}
int main()
{
    return 0;
}
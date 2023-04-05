//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0
#include<iostream>
using namespace std;

//memoized approach 
int solve(int n, vector<int> &heights, vector<int> &dp){
    if(n == 0)  return 0;

    if(dp[n] != -1) return dp[n];

    int a = abs(heights[n] - heights[n-1]) + solve(n-1, heights, dp);
    int b = INT_MAX;
    if(n>1)
        b = abs(heights[n]-heights[n-2]) + solve(n-2, heights, dp);
    return dp[n] = min(a,b);
}
int frogJump(int n, vector<int> &heights)
{   
    vector<int> dp(heights.size(), -1);
    return solve(heights.size()-1, heights, dp);
}
//tabular approach 
int frogJump(int n, vector<int> &heights)
{   
    vector<int> dp(heights.size(), 0);
    for(int i = 1; i<heights.size(); i++){
        int a = abs(heights[i] - heights[i-1]) + dp[i-1];
        int b = INT_MAX;
        if(i>1)
            b = abs(heights[i]-heights[i-2]) + dp[i-2];
        dp[i] = min(a,b);
    }
    return dp[heights.size()-1];
}
//space optimized approach 
int frogJump(int n, vector<int> &heights)
{   
    int prev1 = 0;
    int prev2 = 0;
    int curr;
    for(int i = 1; i<heights.size(); i++){
        int a = abs(heights[i] - heights[i-1]) + prev1;
        int b = INT_MAX;
        if(i>1)
            b = abs(heights[i]-heights[i-2]) + prev2;
        curr = min(a,b);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{
    return 0;
}
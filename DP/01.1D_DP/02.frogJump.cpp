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

int main()
{
    return 0;
}
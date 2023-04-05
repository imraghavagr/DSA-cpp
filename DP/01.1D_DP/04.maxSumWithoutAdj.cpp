//https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-without-adjacents
#include<iostream>
using namespace std;

// memoization
int solve(int *arr, int idx, vector<int> &dp){
    if(idx == 0)    return arr[0];
    if(idx < 0) return 0;
    if(dp[idx] != -1)   return dp[idx];
    //pick or not pick 
    int pick = arr[idx] + solve(arr, idx-2, dp);
    int notPick = 0 + solve(arr, idx-1, dp);
    
    return dp[idx] = max(pick, notPick);
}
// calculate the maximum sum with out adjacent
int findMaxSum(int *arr, int n) {
    vector<int> dp(n, -1);
    return solve(arr, n-1, dp);
}
//tabulation - 

int main()
{
    return 0;
}
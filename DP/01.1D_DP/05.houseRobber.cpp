//https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stickler-theif-
#include<iostream>
using namespace std;
//memoization
int solve(int *arr, int index, vector<int> &dp){
    if(index == 0){
        //this means we have not picked up the 1st index 
        return arr[0];
    }
    if(index < 0)   return 0;
    if(dp[index] != -1) return dp[index];
    //pick 
    int pick = arr[index] + solve(arr, index-2, dp);
    //not pick 
    int notPick = 0 + solve(arr, index-1, dp);
    return dp[index] = max(pick, notPick);
}
int FindMaxSum(int arr[], int n)
{
    // Your code here
    vector<int> dp(n, -1);
    return solve(arr, n-1, dp);
}
//tabular
int solve(int *arr, int n){
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for(int i = 1; i<n; i++){
        //pick or not pick 
        int pick = arr[i];
        if(i>1)  pick += dp[i-2];
        int notPick = 0 + dp[i-1];
        dp[i] = max(pick, notPick);
    }
    return dp[n-1];
}
int main()
{
    return 0;
}
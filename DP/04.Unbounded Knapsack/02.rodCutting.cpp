//exactly same as unbounded knapsack problem
//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#
#include<iostream>
using namespace std;

//recursion + memoisation 
int solve(int n, int len, int *price, vector<int> &rodLen, vector<vector<int>> &dp){
    if(n == 0)  return 0;
    if(len == 0)    return 0;
    if(dp[n][len] != -1)    return dp[n][len];
    if(rodLen[n-1] <= len){
        return dp[n][len] = max(price[n-1] + solve(n, len-rodLen[n-1], price, rodLen, dp), solve(n-1, len, price, rodLen, dp));
    }
    else{
        return dp[n][len] = solve(n-1, len, price, rodLen, dp);
    }
}
int cutRod(int price[], int n) {
    vector<int> rodLengths(n);
    for(int i = 0; i<n; i++)    rodLengths[i] = i+1;
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(n,n,price, rodLengths, dp);
}

//tabulation 
int cutRod(int price[], int n) {
    vector<int> rodLen(n);
    for(int i = 0; i<n; i++)    rodLen[i] = i+1;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(rodLen[i-1] <= j){
                dp[i][j] = max(price[i-1] + dp[i][j-rodLen[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][n];
}

//space optimisation 
int cutRod(int price[], int n) {
    vector<int> rodLen(n);
    for(int i = 0; i<n; i++)    rodLen[i] = i+1;
    
    vector<int> prev(n+1, 0);
    vector<int> curr(n+1, 0);
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(rodLen[i-1] <= j){
                curr[j] = max(price[i-1] + curr[j-rodLen[i-1]], prev[j]);
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[n];
}
int main()
{
    return 0;
}
/*
https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#

Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.
*/
#include<iostream>
using namespace std;

//recursion + memoization
int solve(int n, int w, int *val, int *wt, vector<vector<int>> &dp){
    if(w == 0){
        return 0;
    }
    if(n == 0){
        return 0;
    }
    if(dp[n][w] != -1)  return dp[n][w];
    if(wt[n-1] <= w){
        //two choices - take it or leave it 
        return dp[n][w] = max(val[n-1]+solve(n, w-wt[n-1], val, wt, dp), solve(n-1, w, val, wt, dp));
    }
    else{
        //only one choice 
        return dp[n][w] = solve(n-1, w, val, wt, dp);
    }
}
int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
    return solve(N, W, val, wt, dp);
}

//tabular approach 
int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=W; j++){
            if(wt[i-1] <= j){
                //two choices - take it or leave it 
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                //only one choice 
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][W];
}

//space optimised tabular approach 
int knapSack(int N, int W, int val[], int wt[])
{
    vector<int> prev(W+1, 0);
    vector<int> curr(W+1, 0);
    
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=W; j++){
            if(wt[i-1] <= j){
                //two choices - take it or leave it 
                curr[j] = max(val[i-1]+curr[j-wt[i-1]], prev[j]);
            }
            else{
                //only one choice 
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[W];
}

int main()
{   
    int val[] = {10,20,30};
    int wt[] =  {1,1,1};
    int w = 2; //knapsack capacity
    int n = sizeof(val)/sizeof(int);
    cout<<knapSack(w,wt,val,n)<<endl;
    return 0;
}
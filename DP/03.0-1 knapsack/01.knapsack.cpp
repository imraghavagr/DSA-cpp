/*
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
There are three approaches:
    1.Recursive Code
    2.Recursive Code + Matrix (memoization) = DP[Top-Down Approach]
    3.Tabular Approach (DP- Bottom Up Approach)
*/
//recursive approach
#include<iostream>
using namespace std;
int knapsack(int*wt, int*val, int n, int w){
    //base case
    if(n==0 || w == 0){
        return 0;
    }

    //rec case
    if(wt[n-1] <= w){
        //if wt of item <= w (bag capacity) then two choices- either select the item or do not select it
        int choice1 = val[n-1] + knapsack(wt,val,n-1,w-wt[n-1]);
        int choice2 = knapsack(wt,val,n-1,w);
        return max(choice1,choice2);
    }
    else{
        //wt of the item exceeds w, then do not pick the item
        return knapsack(wt,val,n-1,w);
    }
}
//memoization approach 
int solve(vector<vector<int>>&t, int W, int wt[], int val[], int n){
    //base case
    if(n==0 || W==0){
        return 0;
    }
    if(t[n][W] != -1){
        return t[n][W];
    }
    
    //rec case
    if(wt[n-1]<=W){
        return t[n][W] = max(val[n-1]+solve(t,W-wt[n-1],wt,val,n-1),solve(t,W,wt,val,n-1));
    }
    else{
        return t[n][W] = solve(t,W,wt,val,n-1);
    }
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
    // Your code here
    vector<vector<int>>t(n+1,vector<int>(W+1,-1));
    return solve(t,W,wt,val,n);
    
}
//tabular 
nt knapSack(int W, int wt[], int val[], int n) 
{
    int t[1001][1001];
    
    //Intitialization
    for(int i = 0; i<n+1; i++){
        for(int j= 0; j<W+1; j++){
            if(i == 0 || j== 0){
                t[i][j] = 0;
            }
        }
    }
    
    //filling remaining cells
    for(int i = 1; i<n+1; i++){
        for(int j= 1; j<W+1; j++){
            if(wt[i-1] <= j){
                //two choices- either take this item or do not take this item
                t[i][j] =  max(val[i-1] +t[i-1][j-wt[i-1]],t[i-1][j]);
                
            }
            else{
                // weight of the item exceeds the knapsack capacity
                t[i][j] =  t[i-1][j];
            }       
        }
    }
    return t[n][W];
}
//space optimized 
int knapSack(int W, int wt[], int val[], int n) 
{
    //space optimized approach 
    vector<int> dp(W+1, 0);
    for(int i = 1; i<=n; i++){
        for(int j = W; j>=0; j--){
            if(wt[i-1] <= j){
                dp[j] = max(val[i-1] + dp[j-wt[i-1]], dp[j]);
            }
            // else{
            //     dp[j] = dp[j];
            // }
        }
    }
    return dp[W];
}
int main()
{   
    int val[] = {10,20,30};
    int wt[] =  {1,1,1};
    int w = 2; //knapsack capacity
    int n = sizeof(val)/sizeof(int);
    cout<<knapsack(wt,val,n,w)<<endl;
    return 0;
}
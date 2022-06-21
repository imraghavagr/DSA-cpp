//Recursive approach + Memoization = DP [Top Down Approach]
//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
#include<iostream>
#include<cstring>
using namespace std;

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
        return solve(t,W,wt,val,n-1);
    }
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
    // Your code here
    vector<vector<int>>t(n+1,vector<int>(W+1,-1));
    return solve(t,W,wt,val,n);
    
}
int main()
{   
    int val[] = {10,20,30};
    int wt[] =  {1,1,1};
    int w = 2; //knapsack capacity
    int n = sizeof(val)/sizeof(int);
    cout<<knapsack(W,wt,val,n)<<endl;
    return 0;
}
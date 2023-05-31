//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
//given an array, and a sum , return true if there exists a subset of the array whose sum is equal to given sum value.
//given that array does not contains 0
//T= O(sum*N)
#include<iostream>
#include<vector>
using namespace std;

//memoized recursion approach 
bool solve(int n, int sum, vector<int> &arr, vector<vector<int>> &dp){
    if(sum == 0)    return 1;
    if(n == 0)  return 0;
    if(dp[n][sum] != -1)    return dp[n][sum];
    if(arr[n-1] <= sum) return dp[n][sum] = solve(n-1, sum-arr[n-1], arr, dp) || solve(n-1, sum, arr, dp);
    else    return dp[n][sum] = solve(n-1, sum, arr, dp);
}
bool isSubsetSum(vector<int>arr, int sum){
    // code here 
    vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1, -1));
    return solve(arr.size(), sum, arr, dp);
}
//space optimized tabular approach 
bool isSubsetSum(vector<int>arr, int sum){
    vector<int> prev(sum+1, 0);
    vector<int> curr(sum+1, 0);
    prev[0] = 1;
    curr[0] = 1;
    for(int i = 1; i<=arr.size(); i++){
        for(int j = 1; j<=sum; j++){
            if(arr[i-1] <= j){
                curr[j] = prev[j-arr[i-1]] || prev[j];
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[sum];
}
int main()
{
    vector<int> v = {3,34,4,12,5,2}; //ans = yes/1
    int sum = 9;
    cout<<isSubsetSumTabular(v,sum)<<endl;
    return 0;
}
/*Memozised approach

bool solve(vector<int>&arr, int n, int sum){
    if(n==0 && sum==0){
        return 1;
    }
    if(sum == 0)    return 1; //empty subset will exist with sum = 0
    if(n == 0)  return 0;
    
    //mem code
    if(t[n][sum] != -1)   return t[n][sum];
    //rec case
    if(arr[n-1]<=sum){
        t[n][sum] = solve(arr,n-1,sum-arr[n-1]) || solve(arr,n-1,sum);
    }
    else{
        t[n][sum] = solve(arr,n-1,sum);
    }
    return t[n][sum];
}
    */
// 0 is also present in the array .. 
//so if nums = {0,1,0} and sum = 1
//possible answers are - (0,1), (1,0), (1), (0,1,0)... i.e. total 4 required subsets are present 

//there will be the slight change in the base case 
/*
earlier it was 
if(sum == 0)    return 1;
if(n == 0)  return 0;

change it to...
//do not stop at sum = 0, because adding or not adding 0 will give two choices 
if(n == 0){
    if(sum == 0)    return 1;
    else    return 0;
}
*/

//for tabulation =>
//then instead of i->1 to n and j->1 to sum, do i->1 to n and j-> 0 to sum
//just change j=1 to j=0 in initialisation of the inner for loop in the code other than initialization.
#include<iostream>
using namespace std;

//recursion + memoization 
int solve(int n, int sum, int *arr, vector<vector<int>> &dp){
    if(n == 0){
        if(sum == 0) return 1;
        else return 0;
    }
    if(dp[n][sum] != -1)    return dp[n][sum];
    if(arr[n-1] <= sum){
        return dp[n][sum] = (solve(n-1, sum - arr[n-1], arr, dp)%M + solve(n-1, sum, arr, dp)%M)%M;
    }
    else    return dp[n][sum] = solve(n-1, sum, arr, dp)%M;
}
int perfectSum(int arr[], int n, int sum)
{   
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    return solve(n, sum, arr, dp);
}

//tabular 
int perfectSum(int arr[], int n, int sum)
{   
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=sum; j++){
            if(arr[i-1]<=j){
                dp[i][j] = (dp[i-1][j-arr[i-1]]%M + dp[i-1][j]%M)%M;
            }
            else{
                dp[i][j] = dp[i-1][j]%M;
            }
        }
    }
    return dp[n][sum];
}

//space optimised 
int perfectSum(int arr[], int n, int sum)
{   
    vector<int> prev(sum+1, 0);
    prev[0]  = 1;

    for(int i = 1; i<=n; i++){
        vector<int> curr(sum+1, 0);
        for(int j = 0; j<=sum; j++){
            if(arr[i-1]<=j){
                curr[j] = (prev[j-arr[i-1]]%M + prev[j]%M)%M;
            }
            else{
                curr[j] = prev[j]%M;
            }
        }
        prev = curr;
    }
    return prev[sum];
}
int main()
{
    int arr[] = {1,2,3,4,0};
    int n = sizeof(arr)/sizeof(int);
    int sum = 6;
    cout<<findNumSubsets(arr,n,sum)<<endl;//3 for this input
    return 0;
}
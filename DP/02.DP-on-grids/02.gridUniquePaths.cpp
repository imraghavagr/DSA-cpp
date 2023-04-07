#include<iostream>
using namespace std;
//memoized approach
int solve(int i, int j, vector<vector<int>> &dp){
    if(i == 0 && j == 0)    return 1;
    if(i < 0 || j<0)    return 0;
    if(dp[i][j] != -1)  return dp[i][j];
    //we have to options - go up or go left 
    int up = solve(i-1, j, dp);
    int left = solve(i, j-1, dp);
    return dp[i][j] = up + left;
}
//tabular approach 
int solve(int a, int b){
    vector<vector<int>> dp(a, vector<int> (b, 0));
    //intitialization 
    for(int i = 0; i<a; i++)    dp[i][0] = 1;
    for(int j = 0; j<b; j++)    dp[0][j] = 1;
    for(int i = 1; i<a; i++){
        for(int j = 1; j<b; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[a-1][b-1];
}
//space optimized approach 

int main()
{
    return 0;
}
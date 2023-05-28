#include<iostream>
using namespace std;
//memoization approach
int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i == 0 && j == 0)    return grid[i][j];
    if(i<0 || j<0)  return 1e9;        
    if(dp[i][j] != -1)  return dp[i][j];
    int up = grid[i][j] + solve(i-1, j, grid, dp);
    int left = grid[i][j] + solve(i, j-1, grid, dp);
    return dp[i][j] = min(up, left);
}
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m-1, n-1, grid, dp);
}
//tabulation 
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(i == 0 && j == 0)    dp[i][j] = grid[0][0];
            else{
                //neglect the path if we can't go further up
                int up = 1e9;
                //neglect the path if we can't go further left
                int left = 1e9;
                //calculate up and left normally, if we can go up and left
                if(i>0) up = grid[i][j] + dp[i-1][j];
                if(j>0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[m-1][n-1];
}
//space optimization
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n, 0);
    for(int i = 0; i<m; i++){
        vector<int> curr(n, 0);
        for(int j = 0; j<n; j++){
            if(i == 0 && j == 0)    curr[0] = grid[0][0];
            else{
                //neglect the path if we can't go further up
                int up = 1e9;
                //neglect the path if we can't go further left
                int left = 1e9;
                //calculate up and left normally, if we can go up and left
                if(i>0) up = grid[i][j] + prev[j];
                if(j>0) left = grid[i][j] + curr[j-1];
                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[n-1];
}
int main()
{
    return 0;
}
#include<iostream>
using namespace std;
//rec + memoization 
int solve(int i, int j, vector<vector<int>> &grid,
vector<vector<int>> &dp){
    if(i == 0 && j == 0)    return 1;
    if(i<0 || j<0)  return 0;
    if(dp[i][j] != -1)  return dp[i][j];
    //now we can go either left or up 
    int left = 0, up = 0;
    if(i>0 && !grid[i-1][j])    up = solve(i-1, j, grid, dp);
    if(j>0 && !grid[i][j-1])    left = solve(i, j-1, grid, dp);
    return dp[i][j] = left+up;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    
    if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1]) return 0;

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m-1, n-1, obstacleGrid, dp);
}
//tabular
int solve(int m, int n, vector<vector<int>> &grid,
vector<vector<int>> &dp){
    dp[0][0] = 1;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            //now we can go either left or up 
            if(i == 0 && j == 0)    continue;
            if(grid[i][j] == 1){
                dp[i][j] = 0;
                continue;
            }
            int left = 0, up = 0;
            if(i>0)    up = dp[i-1][j];
            if(j>0)    left = dp[i][j-1];
            dp[i][j] = left+up;
        }
    }
    return dp[m-1][n-1];
}
//space optimized 
int solve(int m, int n, vector<vector<int>> &grid){
    vector<int> prev(n, 0);
    for(int i = 0; i<m; i++){
        vector<int> curr(n, 0);
        for(int j = 0; j<n; j++){
            //now we can go either left or up 
            if(i == 0 && j == 0){
                curr[i] = 1;
                continue;
            }
            if(grid[i][j] == 1){
                curr[j] = 0;
                continue;
            }
            int left = 0, up = 0;
            if(i>0)    up = prev[j];
            if(j>0)    left = curr[j-1];
            curr[j] = left+up;
        }
        prev = curr;
    }
    return prev[n-1];
}
int main()
{
    return 0;
}
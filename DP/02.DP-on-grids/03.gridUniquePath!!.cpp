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
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size(); 
    int n = grid[0].size(); 
    if(grid[m-1][n-1] == 1) return 0; 
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // return solve(m-1, n-1, grid, dp);
    dp[0][0] = 1; 
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(i == 0 && j == 0)    continue;

            int up = 0, left = 0; 
            if(i>0 && grid[i-1][j] == 0){
                up = dp[i-1][j];
            }
            if(j>0 && grid[i][j-1] == 0){
                left = dp[i][j-1];
            }
            dp[i][j] = up+left;
        }
    }
    return dp[m-1][n-1];
}
//space optimized 
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size(); 
    int n = grid[0].size(); 
    if(grid[m-1][n-1] == 1) return 0; 
    vector<int> prev(n, 0), curr(n, 0);
    curr[0] = 1; 
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(i == 0 && j == 0)    continue;

            int up = 0, left = 0; 
            if(i>0 && grid[i-1][j] == 0){
                up = prev[j];
            }
            if(j>0 && grid[i][j-1] == 0){
                left = curr[j-1];
            }
            curr[j] = up+left;
        }
        prev = curr; 
    }
    return prev[n-1];
}
int main()
{
    return 0;
}
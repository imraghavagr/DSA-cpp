#include<iostream>
using namespace std;
//recursion + memoization
vector<int> delC = {-1, 0, 1};
int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    //boundary check 
    if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())    return -1e8;
    //reached goal 
    if(i == grid.size()-1){
        if(j1 == j2)    return grid[i][j1];
        else    return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    //we have 9 movement choices- for every choice robot1 makes, robot2 has 3 choices 
    int maxi = INT_MIN;
    for(int delJ1 : delC){
        for(int delJ2 : delC){
            if(j1 == j2){
                maxi = max(maxi, grid[i][j1] + f(i+1, j1+delJ1, j2+delJ2, grid, dp));
            }
            else{
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i+1, j1+delJ1, j2+delJ2, grid,dp));
            }
        }
    }
    return dp[i][j1][j2] = maxi;
}
//tabulation 
int solve(int n, int m, vector<vector<int>>& grid) {
    // code here
    vector<vector<vector<int>>> dp(n, (vector<vector<int>>(m, vector<int>(m, -1))));
    for(int j1 = 0; j1<m; j1++){
        for(int j2 = 0; j2<m; j2++){
            if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
            else    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }
    for(int i = n-2; i>=0; i--){
        for(int j1 = 0; j1<m; j1++){
            for(int j2 = 0; j2<m; j2++){
                int maxi = INT_MIN;
                for(int delJ1 : delC){
                    for(int delJ2 : delC){
                        if(j1+delJ1 <0 || j1+delJ1>=m || j2+delJ2 < 0 || j2+delJ2>=m){
                            maxi = max(maxi, INT_MIN);
                        }
                        else{
                            if(j1 == j2){
                                maxi = max(maxi, grid[i][j1] + dp[i+1][j1+delJ1][j2+delJ2]);
                            }
                            else{
                                maxi = max(maxi, grid[i][j1] + grid[i][j2] + dp[i+1][j1+delJ1][j2+delJ2]);
                            }
                        }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}
int solve(int n, int m, vector<vector<int>>& grid) {
    // code here
    vector<vector<vector<int>>> dp(n, (vector<vector<int>>(m, vector<int>(m, -1))));
    return f(0,0,m-1, grid, dp);
}
//space optimized 
int solve(int n, int m, vector<vector<int>>& grid) {
    vector<vector<int>> prev(m, vector<int>(m, 0));
    for(int j1 = 0; j1<m; j1++){
        for(int j2 = 0; j2<m; j2++){
            if(j1 == j2){
                prev[j1][j2] = grid[n-1][j1];
            }
            else{
                prev[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }
    
    for(int i = n-2; i>=0; i--){
        vector<vector<int>> curr(m, vector<int>(m, 0));
        for(int j1 = 0; j1<m; j1++){
            for(int j2 = 0; j2<m; j2++){
                int maxi = INT_MIN;
                for(int delJ1 : delC){
                    for(int delJ2 : delC){
                        if(j1+delJ1<0 || j1+delJ1==grid[0].size() || j2+delJ2<0 || j2+delJ2==grid[0].size()){
                            maxi = max(maxi, INT_MIN);
                        }
                        else{
                            if(j1 == j2){
                                maxi = max(maxi, grid[i][j1] + prev[j1+delJ1][j2+delJ2]);
                            }
                            else{
                                maxi = max(maxi, grid[i][j1] + grid[i][j2]+ prev[j1+delJ1][j2+delJ2]);
                            }
                        }
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        prev = curr;
    }
    return prev[0][m-1];
}
int main()
{
    return 0;
}
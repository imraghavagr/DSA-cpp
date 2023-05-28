#include<iostream>
using namespace std;
//rec + memoization 
int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(j<0 || j>=matrix.size()) return 1e9;
    if(i == 0)  return matrix[i][j];
    if(dp[i][j] != -1)  return dp[i][j];
    int up = matrix[i][j] + solve(i-1, j, matrix,dp);
    int leftDiag = matrix[i][j] + solve(i-1, j-1, matrix, dp);
    int rightDiag = matrix[i][j] + solve(i-1, j+1, matrix, dp);

    return dp[i][j] = min(up, min(leftDiag, rightDiag));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int ans = INT_MAX;
    for(int j = 0; j<matrix.size(); j++){
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), -1));
        ans = min(ans, solve(matrix.size()-1, j, matrix, dp));
    }
    return ans;
}
//tabular 
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), 0));        
    for(int j = 0; j<n; j++){
        dp[0][j] = matrix[0][j];
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<n; j++){
            int leftDiag = 1e9;
            int rightDiag = 1e9;
            int up = matrix[i][j] + dp[i-1][j];
            if(j-1 >= 0) leftDiag = matrix[i][j] + dp[i-1][j-1];
            if(j+1 < n) rightDiag = matrix[i][j] + dp[i-1][j+1];
            dp[i][j] = min(up, min(leftDiag, rightDiag));
        }
    }
    int ans = INT_MAX;
    for(int j = 0; j<n; j++){
        ans = min(ans, dp[n-1][j]);
    }
    return ans;
}
//space optimized approach 
int n = matrix.size();
    vector<int> prev(n, 0);
    for(int j = 0; j<n; j++){
        prev[j] = matrix[0][j];
    }
    for(int i = 1; i<n; i++){
        vector<int> curr(n, 0);
        for(int j = 0; j<n; j++){
            int leftDiag = 1e9;
            int rightDiag = 1e9;
            int up = matrix[i][j] + prev[j];
            if(j-1 >= 0) leftDiag = matrix[i][j] + prev[j-1];
            if(j+1 < n) rightDiag = matrix[i][j] + prev[j+1];
            curr[j] = min(up, min(leftDiag, rightDiag));
        }
        prev = curr;
    }
    int ans = INT_MAX;
    for(int j = 0; j<n; j++){
        ans = min(ans, prev[j]);
    }
    return ans;
int main()
{
    return 0;
}
#include<iostream>
using namespace std;
//recrusion + memoization approach
int solve(int i, int j, vector<vector<int>> &triangle,vector<vector<int>> &dp){
    //if we reach the top most element
    if(i == triangle.size()-1){
        return triangle[i][j];
    }
    if(dp[i][j] != -1)  return dp[i][j];
    int down = triangle[i][j] + solve(i+1, j, triangle, dp);
    int downRight = triangle[i][j] + solve(i+1, j+1, triangle, dp);
    return dp[i][j] = min(down, downRight);
}
int minimumTotal(vector<vector<int>>& triangle) {        
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
    return solve(0,0,triangle, dp);
}
//tabulation 
int minimumTotal(vector<vector<int>>& triangle) {        
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    //in recursion we went from 0 to n-1 .. so, in tabulatio we have to go from n-1 to 0
    //therefore our base case will be the last row of dp table 
    //intialisation 
    for(int j = 0; j<n; j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    //filling up the remaining cells 
    for(int i = n-2; i>=0; i--){
        for(int j = i; j>=0; j--){
            int down = triangle[i][j] + dp[i+1][j];
            int downRight = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, downRight);
        }
    }
    return dp[0][0];
}
//space optimized tabular approach 
int minimumTotal(vector<vector<int>>& triangle) {        
    int n = triangle.size();
    vector<int> prev(n, 0);
    //in recursion we went from 0 to n-1 .. so, in tabulatio we have to go from n-1 to 0
    //therefore our base case will be the last row of dp table 
    //intialisation 
    for(int j = 0; j<n; j++){
        prev[j] = triangle[n-1][j];
    }
    //filling up the remaining cells 
    for(int i = n-2; i>=0; i--){
        vector<int> curr(n, 0);
        for(int j = i; j>=0; j--){
            int down = triangle[i][j] + prev[j];
            int downRight = triangle[i][j] + prev[j+1];
            curr[j] = min(down, downRight);
        }
        prev = curr;
    }
    return prev[0];
}
int main()
{
    return 0;
}
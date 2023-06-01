#include<iostream>
using namespace std;
//recursion + memoization 
int solve(int m, int n, string &a, string &b, vector<vector<int>> &dp){
    if(m == 0)  return n;
    if(n == 0)  return m;
    if(dp[m][n] != -1)  return dp[m][n];
    if(a[m-1] == b[n-1]){
        return dp[m][n] = solve(m-1,n-1,a,b,dp);
    }
    else{
        //we have three options - insert, delete and replace 
        int insertOp = 1 + solve(m, n-1, a, b,dp);
        int deleteOp = 1 + solve(m-1, n, a, b,dp);
        int replaceOp = 1 + solve(m-1, n-1, a, b,dp);

        return dp[m][n] = min(insertOp, min(deleteOp, replaceOp));
    }
}
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    return solve(m,n,word1,word2, dp);
}

//tabular 
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    
    //intitialization 
    for(int j = 0; j<=n; j++)   dp[0][j] = j;
    for(int i = 0; i<=m; i++)   dp[i][0] = i;

    //fill remaining cells
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                //we have three options - insert, delete and replace 
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }
    return dp[m][n];
}

//space optimization 
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    vector<int> prev(n+1, 0);
    vector<int> curr(n+1, 0);
    
    //intitialization 
    for(int j = 0; j<=n; j++)   prev[j] = j;
    //fill remaining cells
    for(int i = 1; i<=m; i++){    
        curr[0] = i;        
        for(int j = 1; j<=n; j++){
            if(word1[i-1] == word2[j-1]){
                curr[j] = prev[j-1];
            }
            else{
                //we have three options - insert, delete and replace 
                curr[j] = 1 + min(curr[j-1], min(prev[j], prev[j-1]));
            }
        }
        prev = curr;
    }
    return prev[n];
}
int main()
{
    return 0;
}
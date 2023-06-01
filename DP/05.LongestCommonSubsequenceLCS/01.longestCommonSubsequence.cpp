#include<iostream>
#include<string>
using namespace std;

//recursion + memoisation 
int solve(int m, int n, string str1, string str2, vector<vector<int>> &dp){
    if(m == 0 || n == 0)    return 0;
    if(dp[m][n] != -1)  return dp[m][n];
    if(str1[m-1] == str2[n-1]){
        return dp[m][n] = 1 + solve(m-1, n-1, str1, str2, dp);
    }
    else{
        return dp[m][n] = max(solve(m-1,n,str1,str2, dp), solve(m, n-1, str1, str2, dp));
    }
}
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    return solve(m, n, text1, text2, dp);
}

//tabulation approach - bottom up dp 
int longestCommonSubsequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }        
    return dp[m][n];
}

//space optimised tabulation 
int longestCommonSubsequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<int> prev(n+1, 0);
    vector<int> curr(n+1, 0);        
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(str1[i-1] == str2[j-1]){
                curr[j] = 1 + prev[j-1];
            }
            else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }        
    return prev[n];
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int m = s1.length();
    int n = s1.length();
    cout<<longestCommonSubsequence(s1,s2,m,n)<<endl;
    return 0;
}
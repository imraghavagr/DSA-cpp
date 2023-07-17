//https://leetcode.com/problems/wildcard-matching/description/
#include<iostream>
using namespace std;

//recursion + memoization 
bool solve(int m, int n, string &s, string &p, vector<vector<int>> &dp){
    if(m == 0 && n == 0)    return true;
    if(m == 0)  return false;
    if(n == 0){
        //return true if all the remaining chars in s are '*'
        for(int i = 0; i<m; i++){
            if(s[i] != '*') return false;
        }
        return true;
    }
    if(dp[m][n] != -1)  return dp[m][n];
    if(s[m-1] == p[n-1] || s[m-1] == '?')   return dp[m][n] = solve(m-1, n-1, s, p, dp);
    else{
        if(s[m-1] == '*'){
            return dp[m][n] = solve(m-1, n, s, p, dp) || solve(m, n-1, s, p, dp);
        }
        else    return dp[m][n] = false;
    }
}
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    //string p is the pattern here, i.e. it can contain * or ? 
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return solve(n,m,p,s, dp);
}   

//tabular approach 
bool isMatch(string s, string p) {
    if(s == p)  return true;
    int m = s.length(), n = p.length();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = true;
    for(int j = 1; j<=n; j++){
        bool ret = true; 
        for(int k = 0; k<j; k++){
            if(p[k] != '*'){
                ret = false;
                break;
            }
        }
        dp[0][j] = ret;
    }
    for(int i = 1; i<=m; i++)   dp[i][0] = false;

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*'){
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[m][n];
}

//space optimization
bool isMatch(string s, string p) {
    if(s == p)  return true;
    int m = s.length(), n = p.length();
    vector<bool> prev(n+1, false), curr(n+1, false);
    prev[0] = true;
    for(int j = 1; j<=n; j++){
        bool ret = true; 
        for(int k = 0; k<j; k++){
            if(p[k] != '*'){
                ret = false;
                break;
            }
        }
        prev[j] = ret;
    }
    curr[0] = false;

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?'){
                curr[j] = prev[j-1];
            }
            else if(p[j-1] == '*'){
                curr[j] = curr[j-1] || prev[j];
            }
            else{
                curr[j] = false;
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
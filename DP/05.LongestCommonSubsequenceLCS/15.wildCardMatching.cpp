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
int main()
{
    return 0;
}
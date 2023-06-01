#include<iostream>
using namespace std;
//recursive + memoization
int solve(int n, int m, string s, string t, vector<vector<int>> &dp){
    if(m == 0)  return 1;
    if(n == 0)  return 0;
    if(dp[n][m] != -1)  return dp[n][m];
    if(s[n-1] == t[m-1]){
        //two choices .. match it or do not match it 
        return dp[n][m] = solve(n-1, m-1, s, t, dp) + solve(n-1, m, s, t, dp);
    }
    else{
        return dp[n][m] = solve(n-1, m, s, t, dp);
    }
}
int numDistinct(string s, string t) {
    //we need to find how many occurences of string t occur in string s
    vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));
    return solve(s.length(), t.length(), s, t, dp);
}

//tabular approach 
int numDistinct(string s, string t) {
    //we need to find how many occurences of string t occur in string s
    vector<vector<double>> dp(s.length()+1, vector<double>(t.length()+1, 0));
    for(int i = 0; i<=s.length(); i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i<=s.length(); i++){
        for(int j = 1; j<=t.length(); j++){
            if(s[i-1] == t[j-1]){
                //two choices .. match it or do not match it 
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            } 
        }
    }
    return (int)dp[s.length()][t.length()];
}

//space optimisation 
int numDistinct(string s, string t) {
    vector<double> prev(t.length()+1, 0);
    vector<double> curr(t.length()+1, 0);
    prev[0] = curr[0] = 1;
    for(int i = 1; i<=s.length(); i++){
        for(int j = 1; j<=t.length(); j++){
            if(s[i-1] == t[j-1]){
                //two choices .. match it or do not match it 
                curr[j] = prev[j-1] + prev[j];
            }
            else{
                curr[j] = prev[j];
            } 
        }
        prev = curr;
    }
    return (int)prev[t.length()];
}

//1D array space optimisation
int numDistinct(string s, string t) {
    vector<double> curr(t.length()+1, 0);
    curr[0] = 1;
    for(int i = 1; i<=s.length(); i++){
        for(int j = t.length(); j>=1; j--){
            if(s[i-1] == t[j-1]){
                //two choices .. match it or do not match it 
                curr[j] = curr[j-1] + curr[j];
            }
            else{
                curr[j] = curr[j];
            } 
        }
    }
    return (int)curr[t.length()];
}
int main()
{
    return 0;
}
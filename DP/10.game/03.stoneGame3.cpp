#include<iostream>
using namespace std;
//memoization
int f(int i, vector<int> &s, vector<int> &dp){
    if(i >= s.size())   return 0;
    
    if(dp[i] != -1) return dp[i];

    int c1 = s[i] - f(i+1, s, dp);
    int c2 = INT_MIN, c3 = INT_MIN;
    if(i+1 < s.size())  c2 = s[i] + s[i+1] - f(i+2, s, dp);
    if(i+2 < s.size())  c3 = s[i] + s[i+1] +s[i+2] - f(i+3, s, dp);
    return dp[i] = max({c1,c2,c3});
}
string stoneGameIII(vector<int>& s) {
    vector<int> dp(s.size(), -1);
    int maxDiff = f(0,s, dp);
    if(maxDiff == 0)    return "Tie";
    else if(maxDiff > 0)    return "Alice";
    else    return "Bob";
}
//tabular
string stoneGameIII(vector<int>& s) {
    vector<int> dp(s.size()+1, 0);
    for(int i = s.size()-1; i>=0; i--){
        int c1 = s[i] - dp[i+1];
        int c2 = INT_MIN, c3 = INT_MIN;
        if(i+1 < s.size())  c2 = s[i] + s[i+1] - dp[i+2];
        if(i+2 < s.size())  c3 = s[i] + s[i+1] +s[i+2] - dp[i+3];
        dp[i] = max({c1,c2,c3});
    }
    int maxDiff = dp[0];
    if(maxDiff == 0)    return "Tie";
    else if(maxDiff > 0)    return "Alice";
    else    return "Bob";
}
int main()
{
    return 0;
}
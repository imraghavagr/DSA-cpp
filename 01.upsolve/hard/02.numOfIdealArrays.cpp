//https://leetcode.com/problems/count-the-number-of-ideal-arrays/description/
#include<iostream>
using namespace std;
const unsigned int M = 1e9 + 7; 
int solve(int val, int idx, int n, int maxValue, vector<vector<int>> &dp){
    if(idx == n)  return 1; 
    if(dp[idx][val] != -1)  return dp[idx][val];
    int j = 1; 
    long long int cnt = 0; 
    while(val * j <= maxValue){
        cnt = ((cnt)%M + (solve(val*j, idx+1, n, maxValue, dp))%M)%M;
        j++; 
    }
    return dp[idx][val] = cnt; 
}
int idealArrays(int n, int maxValue) {
    long long int cnt = 0; 
    vector<vector<int>> dp(n+1, vector<int>(maxValue+1, -1)); 
    for(int i = 1; i<=maxValue; i++){
        cnt = (cnt + solve(i, 1, n, maxValue, dp))%M;
    }
    return cnt; 
}
int main()
{
    return 0;
}
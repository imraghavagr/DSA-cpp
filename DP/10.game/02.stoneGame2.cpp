#include<iostream>
using namespace std;
int help(int i, int m, vector<int> &p, vector<vector<int>> &dp){
    if(i == p.size())   return 0;
    if(dp[i][m] != -1)  return dp[i][m];
    int sum = INT_MIN;
    int tot = 0;
    //we can pick stones in range [1, 2*m]
    for(int j = 0; j<2*m; j++){
        if(i+j < p.size()){
            //this means there are i+j stones present in the remaining stones 
            tot += p[i+j];
            sum = max(sum, tot-help(i+j+1, max(m,j+1), p, dp));
        }
    }
    return dp[i][m] = sum;
}
int stoneGameII(vector<int>& piles) {
    //let the maximum score obtained by alice is a and that by bob be b
    //so we will calculate a-b using backtracking and dp 
    //then ..we already know a + b .. then we have two equations and two variables 
    //we, can find the value of a by solving them .. 
    //a+b = x 
    //a-b = y
    //a = (x+y)/2
    int x = 0;
    for(auto it : piles)    x += it;
    
    vector<vector<int>> dp(101, vector<int>(201, -1));
    int y = help(0, 1, piles, dp);
    return (x+y)/2;
}
int main()
{
    return 0;
}
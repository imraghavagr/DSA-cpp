#include<iostream>
using namespace std;

//recursion + memoization 
int solve(int i, int buy, vector<int> &prices, vector<vector<int>> &dp){
    if(i >= prices.size())    return 0;
    if(dp[i][buy] != -1)    return dp[i][buy];
    int profit;
    if(buy == 1){
        profit = max(-prices[i] + solve(i+1, 0, prices, dp), solve(i+1, 1, prices, dp));
    }
    else{
        profit = max(prices[i] + solve(i+2, 1, prices, dp), solve(i+1, 0, prices, dp));
    }
    return dp[i][buy] = profit;
}
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return solve(0,1,prices, dp);
}

//tabular 
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2, 0));
    for(int i = n-1; i>=0; i--){
        for(int buy = 0; buy<=1; buy++){
            int profit;
            if(buy == 1){
                profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
            }
            else{
                profit = max(prices[i] + dp[i+2][1], dp[i+1][0]);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

//space optimisation 
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2, 0);
    vector<int> ahead2(2, 0);
    vector<int> curr(2, 0);
    for(int i = n-1; i>=0; i--){
        for(int buy = 0; buy<=1; buy++){
            int profit;
            if(buy == 1){
                profit = max(-prices[i] + ahead[0], ahead[1]);
            }
            else{
                profit = max(prices[i] + ahead2[1], ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead2 = ahead;
        ahead = curr;
    }
    return ahead[1];
}
int main()
{
    return 0;
}
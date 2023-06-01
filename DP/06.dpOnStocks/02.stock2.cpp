//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
#include<iostream>
using namespace std;

//recursion + memoization 
int solve(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp){
    if(idx == prices.size())    return 0;
    if(dp[idx][buy] != -1)  return dp[idx][buy];
    int profit;
    if(buy == 1){
        //we can buy or not buy 
        profit = max(-prices[idx] + solve(idx+1, 0, prices, dp), solve(idx+1, 1, prices, dp));
    }
    else{
        profit = max(prices[idx] + solve(idx+1, 1, prices, dp), solve(idx+1, 0, prices, dp));
    }
    return dp[idx][buy] = profit; 
}
int maxProfit(vector<int>& prices) {
    //buy - 1, means we have no stock holding and we can buy a new stock 
    //buy - 0, means we have a stock holding, so we have to first sell it before buying new stock 
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    
    return solve(0,1,prices, dp);
}

//tabulation 
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;

    for(int idx = n-1; idx>=0; idx--){
        for(int buy = 0; buy<=1; buy++){
            int profit = 0;
            if(buy){
                profit = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
            }
            else{
                profit = max(prices[idx] + dp[idx+1][1], dp[idx+1][0]);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];
}

//space optimization 
//time - O(n*2)
//space - O(2 + 2)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // vector<vector<int>> dp(n+1, vector<int>(2, 0));
    
    //instead of ahead array, we can also use 4 variables 
    //that will bring no change in space complexity
    vector<int> ahead(2, 0), curr(2, 0);
    // dp[n][0] = dp[n][1] = 0;

    for(int idx = n-1; idx>=0; idx--){
        for(int buy = 0; buy<=1; buy++){
            int profit = 0;
            if(buy){
                profit = max(-prices[idx] + ahead[0], ahead[1]);
            }
            else{
                profit = max(prices[idx] + ahead[1], ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}

int main()
{
    return 0;
}
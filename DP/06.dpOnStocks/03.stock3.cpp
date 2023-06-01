//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
#include<iostream>
using namespace std;

//recursion + memoization 
int solve(int i, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
    if(cap == 0)    return 0;
    if(i == prices.size())  return 0;
    if(dp[i][buy][cap] != -1)   return dp[i][buy][cap];
    int profit;
    if(buy){
        profit = max(-prices[i]+solve(i+1, 0, cap, prices, dp), 
                    solve(i+1, 1, cap, prices, dp));
    }
    else{
        profit = max(prices[i] + solve(i+1, 1, cap-1, prices, dp), 
                    solve(i+1, 0, cap, prices, dp));
    }
    return dp[i][buy][cap] = profit;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    //buy - 0/1
    //cap - max transactions allowed - 2
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,-1)));
    return solve(0,1,2,prices, dp);
}

//tabular approach
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));        

    for(int i = n-1; i>=0; i--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap = 1; cap<=2; cap++){
                int profit;
                if(buy){
                    profit = max(-prices[i]+dp[i+1][0][cap],
                                dp[i+1][1][cap]);
                }
                else{
                    profit = max(prices[i] + dp[i+1][1][cap-1],
                                dp[i+1][0][cap]);
                }
                dp[i][buy][cap] = profit; 
                }
            }
    }
    return dp[0][1][2];
}

//space optimization 
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for(int i = n-1; i>=0; i--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap = 1; cap<=2; cap++){
                int profit;
                if(buy){
                    profit = max(-prices[i]+ahead[0][cap],
                                ahead[1][cap]);
                }
                else{
                    profit = max(prices[i] + ahead[1][cap-1],
                                ahead[0][cap]);
                }
                curr[buy][cap] = profit; 
            }
        }
        ahead = curr;
    }
    return ahead[1][2];
}
int main()
{
    return 0;
}
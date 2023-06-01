#include<iostream>
using namespace std;

//recursion + memoization 
int solve(int i, int transNum, vector<int> &prices, vector<vector<int>> &dp, int k){
    if(i == prices.size() || transNum == (2*k)) return 0;
    if(dp[i][transNum] != -1)   return dp[i][transNum];
    int profit;
    if(transNum % 2 == 0){
        profit = max(-prices[i]+solve(i+1, transNum+1, prices, dp, k), 
                    solve(i+1, transNum, prices, dp, k));
    }
    else{
        profit = max(prices[i] + solve(i+1, transNum+1, prices, dp, k), 
                    solve(i+1, transNum, prices,dp, k));
    }
    return dp[i][transNum] =  profit;
}
int maxProfit(int k, vector<int>& prices) {
    //we will maintain transaction number 
    //b s b s
    //0 1 2 3
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>((2*k)+1, -1));
    return solve(0,0,prices, dp, k);
}

//tabular 
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    //we will maintain transaction number 
    //b s b s
    //0 1 2 3
    vector<vector<int>> dp(n+1, vector<int>((2*k)+1, 0));

    for(int i = n-1; i>=0; i--){
        for(int transNum = (2*k)-1; transNum>=0; transNum--){
            int profit;
            if(transNum % 2 == 0){
                profit = max(-prices[i]+ dp[i+1][transNum+1], 
                            dp[i+1][transNum]);
            }
            else{
                profit = max(prices[i] + dp[i+1][transNum+1], 
                            dp[i+1][transNum]);
            }
            dp[i][transNum] =  profit;
        }
    }
    return dp[0][0];
}

//space optimization 
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    //we will maintain transaction number 
    vector<int> ahead((2*k)+1, 0);
    vector<int> curr((2*k)+1, 0);

    for(int i = n-1; i>=0; i--){
        for(int transNum = (2*k)-1; transNum>=0; transNum--){
            int profit;
            if(transNum % 2 == 0){
                profit = max(-prices[i]+ ahead[transNum+1], 
                            ahead[transNum]);
            }
            else{
                profit = max(prices[i] + ahead[transNum+1], 
                            ahead[transNum]);
            }
            curr[transNum] =  profit;
        }
        ahead = curr;
    }
    return ahead[0];
}
int main()
{
    return 0;
}
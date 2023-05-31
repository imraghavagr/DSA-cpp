//https://leetcode.com/problems/coin-change/submissions/
#include<iostream>
#include<climits>
using namespace std;
//recursion + memoisation
int solve(int n, int amount, vector<int> &coins, vector<vector<int>> &dp){
    //if there is no amount left, but coins are remaining, then there is no way to make that change 
    if(amount == 0) return 0;
    //if there are no coins left, but some sum is left, than this can't be possible, so we return..
    //a large value s.t. it does not gets counted while calculation min 
    if(n == 0)  return 1e8;

    if(dp[n][amount] != -1) return dp[n][amount];
    if(coins[n-1] <= amount){
        int take = 1 + solve(n, amount-coins[n-1], coins, dp);
        int notTake = solve(n-1, amount, coins, dp);
        return dp[n][amount] = min(take, notTake);
    }
    else{
        int notTake = solve(n-1, amount, coins, dp);
        return dp[n][amount] = notTake;
    }
}
int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
    int ans = solve(coins.size(), amount, coins, dp);
    if(ans == 1e8)   return -1;
    else return ans;
}
//tabular approach 
int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));

    for(int j = 0; j<=amount; j++){
        dp[0][j] = 1e8;
    }       
    for(int i = 0; i<=coins.size(); i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i<=coins.size(); i++){
        for(int j = 1; j<=amount; j++){
            if(coins[i-1] <= j){
                int take = 1 + dp[i][j-coins[i-1]];
                int notTake = dp[i-1][j];
                dp[i][j] = min(take, notTake);
            }
            else{
                int notTake = dp[i-1][j];
                dp[i][j] = notTake;
            }
        }
    }
    int ans = dp[coins.size()][amount];
    if(ans == 1e8)   return -1;
    else return ans;
}

//space optimised tabular approach 
int coinChange(vector<int>& coins, int amount) {

    vector<int> prev(amount+1, 1e8);
    vector<int> curr(amount+1, 0);
    for(int i = 1; i<=coins.size(); i++){
        for(int j = 1; j<=amount; j++){
            if(coins[i-1] <= j){
                curr[j] = min(1 + curr[j-coins[i-1]], prev[j]);
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    int ans = prev[amount];
    if(ans == 1e8)   return -1;
    else return ans;
}
int main()
{   

    return 0;
}
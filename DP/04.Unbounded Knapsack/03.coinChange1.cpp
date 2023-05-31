/* Same as numberOfSubsets ques. Just add unbounded property.*/

#include<iostream>
using namespace std;

//recursion + memoization 
int solve(int n, int amount, vector<int> &coins, vector<vector<int>> &dp){
    if(amount == 0) return 1;
    if(n == 0)  return 0;
    if(dp[n][amount] != -1) return dp[n][amount];
    if(coins[n-1] <= amount){
        return dp[n][amount] = solve(n, amount-coins[n-1], coins, dp) + solve(n-1, amount, coins, dp);
    }
    else{
        return dp[n][amount] = solve(n-1, amount, coins, dp);
    }
}
int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
    return solve(coins.size(), amount, coins, dp);
}

//tabular approach
int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
    for(int i = 0; i<=coins.size(); i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i<=coins.size(); i++){
        for(int j = 1; j<=amount; j++){
            if(coins[i-1] <= j){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[coins.size()][amount];
}

//space optimised tabular approach 
int change(int amount, vector<int>& coins) {        
    vector<int> prev(amount+1, 0);
    vector<int> curr(amount+1, 0);

    prev[0] = curr[0] = 1;

    for(int i = 1; i<=coins.size(); i++){
        for(int j = 1; j<=amount; j++){
            if(coins[i-1] <= j){
                curr[j] = curr[j-coins[i-1]] + prev[j];
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[amount];
}
int main()
{
    
    return 0;
}
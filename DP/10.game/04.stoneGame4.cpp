#include<iostream>
using namespace std;
//memoization
int solve(int n, vector<int> &dp){
    //if there are no stones left, it means the current player will loose the game
    if(n == 0)  return 0; 
    if(dp[n] != -1) return dp[n];
    //now find out if there is any way s.t. curr player can win the game 
    for(int i = 1; i*i <= n; i++){
        //agar 1 bhi baar agla player haar gaya to current player jeet jaega 
        if(solve(n-(i*i), dp) == 0) return dp[n] = 1;
    }
    return dp[n] = 0;
}
bool winnerSquareGame(int n) {
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}
//tabular
bool winnerSquareGame(int n) {
    vector<int> dp(n+1, 0);
    for(int i = 0; i<=n; i++){
        int flag = 0;
        for(int j = 1; j*j <= i; j++){
            if(dp[i-(j*j)] == 0){
                flag = 1;
                break;
            }
        }
        dp[i] = flag;
    }
    return dp[n];
}
int main()
{
    return 0;
}
//https://leetcode.com/problems/coin-change/submissions/
#include<iostream>
#include<climits>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    
    int n = coins.size();
    int t[n+1][amount+1];  

    for(int j=0; j <= amount; j++)
        t[0][j] = INT_MAX-1;
    for(int i=0; i <= n; i++)
        t[i][0] = 0;
    
    for(int i=1; i < n+1; i++){
        for(int j=1; j < amount+1; j++) {
            if(coins[i-1] <= j)
                t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    //Return the fewest number of coins that you need to make up that amount. 
    //If that amount of money cannot be made up by any combination of the coins, return -1.
    return t[n][amount] > amount ? -1 : t[n][amount]; 
}
int main()
{   

    return 0;
}
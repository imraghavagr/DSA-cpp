#include<iostream>
using namespace std;
//memoiztion
int solve(int s, int e, vector<int> &piles, vector<vector<int>> &dp){
    if(s > e)   return 0; 
    if(dp[s][e] != -1)  return dp[s][e];
    int c1 = piles[s] - solve(s+1, e, piles, dp);
    int c2 = piles[e] - solve(s, e-1, piles, dp);

    return dp[s][e] =  max(c1, c2);
}
bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int maxDiff = solve(0, n-1, piles, dp);
    return maxDiff > 0;
}

/*
We are given that :

the number of piles is always even.
Alex always moves first
The total number of stones is odd, therefore, impossiblity of a tie
given that alex always move first, alex is able to make certain that she always choses iether the odd indices or even indices, for example:

a b c d e f (letters represent piles)
0 1 2 3 4 5 (indices)
alex can chose iether a or f
say alex chooses 'a'
lee is left with b c d e f
doesnt matter what lee chooses now , alex will always have the option to choose c or e in the next turn

thus by this logic we can make sure that alex is able to choose iether odd or even index piles EVERYTIME

therefore,alex simply makes sure that she chooses whichever indices' sum is max (odd idices or even indices).

Hence proved that when alex plays optimally, she always wins
*/
bool stoneGame(vector<int>& piles) {
    //alice can always win the game 
    return true;
}
int main()
{
    return 0;
}
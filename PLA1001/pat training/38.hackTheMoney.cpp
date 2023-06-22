#include<iostream>
#include<vector>
using namespace std;
bool solve(int currNum, int n, vector<int> &dp){
    if(currNum == n)    return true; 
    if(currNum > n) return false; 

    if(dp[currNum] != -1)   return dp[currNum];

    //we have two choices - multiply with 10 or multimply with 20 
    return dp[currNum] = solve(currNum*10, n, dp) || solve(currNum*20, n, dp);
}
bool check(int n){
    if(n == 1)  return true; 
    vector<int> dp(n+1, -1);
    int currNum = 1; 
    return solve(currNum, n, dp);
}
bool solveUsingTabularApproach(int n){
    int currNum = 1; 
    vector<int> dp(n, 0);
    
}
int main()
{   
    int n; 
    cin>>n; 
    cout<<check(n)<<endl;
    return 0;
}
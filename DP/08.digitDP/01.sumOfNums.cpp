//given n, find the sum of all digits of all numbers in the range 1 to n
#include<iostream>
using namespace std;
int fun(int pos, int tight, int sum, string &digits, vector<vector<vector<int>>> &dp){
    if(pos == digits.size())    return sum;
    if(dp[pos][tight][sum] != -1)   return dp[pos][tight][sum];
    int ret = 0; 
    if(tight == 1){
        for(int i = 0; i<= digits[pos]-'0'; i++){
            if(i == digits[pos]-'0'){
                ret += fun(pos+1, 1, sum+i, digits,dp);
            }
            else{
                ret += fun(pos+1, 0, sum+i, digits,dp);
            }
        }
    }
    else{
        for(int i = 0; i<=9; i++){
            ret += fun(pos+1, 0, sum+i, digits, dp);
        }
    }
    return dp[pos][tight][sum] = ret; 
}
int sumOfDigits(int N){
    vector<vector<vector<int>>> dp(8, vector<vector<int>>(2, vector<int>(73, -1)));
    string digits = to_string(N); 
    return fun(0, 1, 0, digits, dp); 
}
int main()
{     
    return 0;
}
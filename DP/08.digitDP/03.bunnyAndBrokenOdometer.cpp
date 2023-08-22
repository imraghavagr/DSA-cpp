//https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/?purpose=login&source=problem-page&update=google

//we need to find the number of numbers in range [1,n] whose any digit is a 3
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//n<=1e9
//pos-> 10 
//tight -> 2
//flag -> 2 
int dp[10][2][2];

int g(int pos, int tight, int flag, string &digits){
    if(pos == digits.size()){
        if(flag == 1)    return 1; 
        else    return 0; 
    }
    if(dp[pos][tight][flag] != -1)   return dp[pos][tight][flag];

    int ret = 0; 
    if(tight == 1){
        for(int i = 0; i<= digits[pos]-'0'; i++){
            int newFlag = flag; 
            if(i == 3)  newFlag = 1; 
            if(i == digits[pos]-'0'){
                ret += g(pos+1, 1, newFlag, digits);
            }
            else{
                ret += g(pos+1, 0, newFlag, digits);
            }
        }
    }
    else{
        for(int i = 0; i<=9; i++){
            int newFlag = flag; 
            if(i == 3)  newFlag = 1; 
            ret += g(pos+1, 0, newFlag, digits);
        }
    }
    return dp[pos][tight][flag] = ret; 
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t; 
    int n; 
    string digits; 

    while(t--){
        cin>>n; 
        //we need to find the number of numbers in the range [l,r] whose sum of digits is prime         
        memset(dp, -1, sizeof(dp));
        digits = to_string(n); 
        cout << n - g(0, 1, 0, digits) << endl; 
    }
    
    return 0;
}
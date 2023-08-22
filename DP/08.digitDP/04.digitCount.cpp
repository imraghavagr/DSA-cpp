//https://lightoj.com/problem/digit-count
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//we can only use the digits given in givenNums vector  and need
//to make n digit number out of it, also no two cons digit diff 
//can be greater than 2 
// n can be a 10 digit number at max 
// we need to make a 10 digit num at max 
//prev digit placed ki value bhi pata honi chahiye - 0, 1, ..., 9
//pos-> 12
//prev -> 10 
int dp[12][10];

int g(int pos, int prev, vector<int> &v, int n){
    if(pos == n){
        return 1; 
    }

    if(dp[pos][prev] != -1)   return dp[pos][prev];

    int ret = 0; 

    for(auto &num : v){
        if(prev == 0 || abs(prev-num) <= 2){
            ret += g(pos+1, num, v, n); 
        }
    }
    return dp[pos][prev] = ret; 
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t; 
    int m,n; 

    for(int i = 1; i<=t; i++){
        cin>>m>>n; 
        vector<int> givenNums(m); 
        for(auto &it : givenNums){
            cin>>it; 
        }
        //we need to find the number of numbers in the range [l,r] whose sum of digits is prime         
        memset(dp, -1, sizeof(dp));
        int ans = g(0, 0, givenNums, n);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    
    return 0;
}
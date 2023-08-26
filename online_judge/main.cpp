#include<bits/stdc++.h>
using namespace std;
#define ll long long int

//pos - 10 
//sum - 10*9 => 92
//tight - 2
ll dp[10][92][2]; 
ll g(string &digits, ll pos = 0, ll tight = 1, ll sum = 0){
    if(pos == digits.size()){
        return sum; 
    }

    if(dp[pos][sum][tight] != -1)   return dp[pos][sum][tight];

    ll ret = 0; 
    ll upperLimit = (tight == 1) ? digits[pos] - '0': 9;

    for(ll i = 0; i<=upperLimit; i++){
        if(tight == 1){
            if(i == upperLimit) ret += g(digits, pos+1, 1, sum + i); 
            else    ret += g(digits, pos+1, 0, sum + i); 
        }   
        else{
            ret += g(digits, pos+1, 0, sum + i); 
        }
    }
    return dp[pos][sum][tight] = ret; 
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll l, r; 
    string digits;

    while(true){
        cin>>l>>r; 
        if(l == -1 && r == -1)  break;
        digits = to_string(r); 
        memset(dp, -1, sizeof(dp));
        ll ans2 = g(digits); 
        memset(dp, -1, sizeof(dp));
        if(l != 0)  l = l - 1; 
        digits = to_string(l); 
        ll ans1 = g(digits); 
        cout<< ans2 - ans1<<endl;
    }    
    return 0;
}
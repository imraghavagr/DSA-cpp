#include<bits/stdc++.h>
using namespace std;
#define ll long long
//1<=l<r<=1e6
//pos = 8
//tight = 0/1 => 2 values 
//sum = 8*9 = 72 (max value)
ll dp[10][2][80];
int p[101];
bool isPrime(ll num){
    //returns true if num is prime or false 
    return p[num];
}
ll g(ll pos, ll tight, ll sum, string &digits){
    if(pos == digits.size()){
        if(isPrime(sum))    return 1; 
        else    return 0; 
    }
    if(dp[pos][tight][sum] != -1)   return dp[pos][tight][sum];

    ll ret = 0; 
    if(tight == 1){
        for(int i = 0; i<= digits[pos]-'0'; i++){
            if(i == digits[pos]-'0'){
                ret += g(pos+1, 1, sum+i, digits);
            }
            else{
                ret += g(pos+1, 0, sum+i, digits);
            }
        }
    }
    else{
        for(int i = 0; i<=9; i++){
            ret += g(pos+1, 0, sum+i, digits);
        }
    }
    return dp[pos][tight][sum] = ret; 
}
void primeSeive(int *p){
    p[0] = p[1] = 0; 
    p[2] = 1; 
    //mark all odds as potential primes
    for(int i = 3; i<=100; i+=2)    p[i] = 1; 

    for(ll i = 3; i*i <= 100; i+=2){
        if(p[i]){
            for(ll j = i*i; j<=100; j+=i){
                p[j] = 0; 
            }
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t; 
    ll l,r; 
    string digits; 

    memset(p, 0, sizeof(p));
    primeSeive(p); 

    while(t--){
        cin>>l>>r; 
        //we need to find the number of numbers in the range [l,r] whose sum of digits is prime 
        
        memset(dp, -1, sizeof(dp));
        digits = to_string(r); 
        ll ans1 = g(0, 1, 0, digits); 
        
        memset(dp, -1, sizeof(dp));
        digits = to_string(l-1); 
        ll ans2 = g(0, 1, 0, digits); 
        cout << ans1-ans2 <<endl; 
    }
    
    return 0;
}
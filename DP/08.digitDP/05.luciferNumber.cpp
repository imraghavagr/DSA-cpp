//spoj - LUCIFER NUMBER 
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[10][60][60][2]; // pod, sumOdd, sumEven, tight
int p[61];
bool isPrime(int num){
    //returns true if num is prime or false 
    return p[num];
}
int g(int pos, int sumOdd, int sumEven, int tight, string &digits){
    if(pos == digits.size()){
        int diff; 
        if(digits.size() % 2 == 0) diff = sumEven - sumOdd;
        else    diff = sumOdd - sumEven;

        if(diff < 0)    return 0; 
        
        if(isPrime(diff))   return 1; 
        else    return 0; 
    }

    if(dp[pos][sumOdd][sumEven][tight] != -1)   return dp[pos][sumOdd][sumEven][tight];

    int ret = 0; 
    if(tight == 1){
        for(int i = 0; i<=digits[pos]-'0'; i++){
            int newSumOdd = sumOdd; 
            int newSumEven = sumEven; 
            if(pos % 2 == 1) newSumOdd += i; 
            else    newSumEven += i; 
            if(i == digits[pos]-'0'){
                ret += g(pos+1, newSumOdd, newSumEven, 1, digits);
            }
            else{
                ret += g(pos+1, newSumOdd, newSumEven, 0, digits);
            }
        }
    }
    else{
        for(int i = 0; i<=9; i++){
            int newSumOdd = sumOdd; 
            int newSumEven = sumEven; 
            if(pos % 2 == 1) newSumOdd += i; 
            else    newSumEven += i; 
            ret += g(pos+1, newSumOdd, newSumEven, 0, digits);
        }
    }
    return dp[pos][sumOdd][sumEven][tight] = ret; 
}
void primeSeive(int *p){
    p[0] = p[1] = 0; 
    p[2] = 1; 
    //mark all odds as potential primes
    for(int i = 3; i<=60; i+=2)    p[i] = 1; 

    for(ll i = 3; i*i <= 60; i+=2){
        if(p[i]){
            for(ll j = i*i; j<=60; j+=i){
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
    int l, r; 
    string digits;

    memset(dp, 0, sizeof(p));
    primeSeive(p); 

    while(t--){
        cin>>l>>r; 
        digits = to_string(r); 
        memset(dp, -1, sizeof(dp));
        int ans2 = g(0, 0, 0, 1, digits); 
        memset(dp, -1, sizeof(dp));
        digits = to_string(l-1); 
        int ans1 = g(0, 0, 0, 1, digits); 
        cout<< ans2 - ans1<<endl;
    }
    
    return 0;
}
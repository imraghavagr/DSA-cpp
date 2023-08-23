//https://www.spoj.com/problems/PR003004/
//find sum of digits of all numbers in range [L, R]
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int

//pos - 16 -> 18
//sum - 16*9 => 144 -> 150 
//tight - 2
ull dp[18][150][2]; 
ull g(string &digits, ull pos = 0, ull tight = 1, ull sum = 0){
    if(pos == digits.size()){
        return sum; 
    }

    if(dp[pos][sum][tight] != -1)   return dp[pos][sum][tight];

    ull ret = 0; 
    ull upperLimit = (tight == 1) ? digits[pos] - '0': 9;

    for(ull i = 0; i<=upperLimit; i++){
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

    int t;
    cin>>t; 
    ull l, r; 
    string digits;

    while(t--){
        cin>>l>>r; 
        digits = to_string(r); 
        memset(dp, -1, sizeof(dp));
        ull ans2 = g(digits); 
        memset(dp, -1, sizeof(dp));
        if(l != 0)  l = l - 1; 
        digits = to_string(l); 
        ull ans1 = g(digits); 
        cout<< ans2 - ans1<<endl;
    }    
    return 0;
}
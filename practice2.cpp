#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
using namespace std;
int isPossible(int x,long long a, long long b, long long c, long long amount){
    long long int val = c; 
    if(val > amount)  return 1;
    val += b*x;
    if(val > amount)    return 1; 
    val += a*x*x;
    if(val == amount)   return 0; 
    else if(val > amount)   return 1; 
    else    return 2;    
}
void solve(long long a, long long b, long long c, long long amount){
    //first lets find the upper limit 
    int s = 1, e = 2; 
    while(isPossible(e,a,b,c,amount) == 2){
        e = 2 * e;
    }
    //now we have range from s to e 
    while(s <= e){
        int mid = s + (e-s)/2; 
        int x = isPossible(mid,a,b,c,amount);
        if(x == 0){
            cout<<mid<<endl;
            return;
        }
        else if(x == 1){
            //we are getting bigger value 
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    long long n, amount;     
    while(t--){        
        cin>>n>>amount;
        // vector<int> v; 
        long long a = 0,b = 0,c = 0;
        for(long long int i = 0; i<n; i++){
            int x; cin>>x; 
            a += 4; 
            b += (4*x);
            c += (x*x);
        }
        solve(a,b,c,amount);
    }
    return 0;
}
//https://online.codingblocks.com/app/player/220176/content/213049/4761/code-challenge
#include<iostream>
using namespace std;
/*
0 1 2 3 ... N

n = 3:
011

" number of set bits in binary rep of n is the ans "
*/
int main(){

    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int ans = 0;
        while(n>0){
            n = n & (n-1);
            ans++;
        }
        cout<<ans<<endl;

    }
    return 0;
}
//given n and p, find the largest power of p that divides n! 
//use n/p approach 
#include<iostream>
using namespace std;
int main()
{   
    int t;
    cin>>t;
    
    while(t--){
        int n,p;
        cin>>n>>p;
        int ans = 0;
        while(n>0){
            n = n/p;
            ans += n;
        }
        cout<<ans<<endl;
    }
    return 0;
}
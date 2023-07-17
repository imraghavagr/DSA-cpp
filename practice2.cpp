#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const unsigned int M = 998244353;
int nCr(int n, int r){
    double ans = 1; 
    for(int i = 1; i<=r; i++){
        ans = ans * (n-r+i)/i;
    }
    return (int)ans;
}
int solve(int n, int k, vector<int> &on, vector<int> &off){
    sort(on.begin(), on.end()); 
    sort(off.begin(), off.end());
    int i = 0, j = 0; 
    int ans = 0; 
    int lamps = 0; 
    while(i<n && j<n){
        if(on[i] <= off[j]){
            if(lamps >= k-1){
                ans += nCr(lamps, k-1)%M;
            }
            lamps++;
            i++;
        }
        else{
            lamps--;
            j++;
        }
    }
    return ans%M;
}
int main()
{   
    int n,k;
    cin>>n>>k;
    vector<int> on, off; 
    int x,y;
    for(int i = 0; i<n; i++){
        cin>>x>>y;
        on.push_back(x);
        off.push_back(y);
    }
    cout<<solve(n,k,on,off)<<endl;
    return 0;
}
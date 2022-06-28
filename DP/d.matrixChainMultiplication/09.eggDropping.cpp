//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1#
#include<bits/stdc++.h>
using namespace std;
int t[201][201];
//Function to find minimum number of attempts needed in 
//order to find the critical floor in worst case.
int solve(int e, int f){
    //base case
    if(f==0 || f==1)return f;
    if(e == 1)return f;
    
    if(t[e][f]!=-1)return t[e][f];
    int ans = INT_MAX;
    for(int k = 1; k<=f; k++){
        int tempAns = 1 + max(solve(e-1,k-1),solve(e,f-k));
        ans = min(ans, tempAns);
    }
    return t[e][f] = ans;
}
int eggDrop(int n, int k) 
{   
    memset(t,-1,sizeof(t));
    return solve(n,k);
}
int main()
{   
    int e,f; // num of eggs and floors 
    cin>>e>>f;
    cout<<eggDrop(e,f)<<endl;
    return 0;
}
/*
if wt > threshold .. charge = 2*base amount 
else if wt< threshold .. charge = 1 dollar  
*/
#include<iostream>
#include<vector>
using namespace std;
int solve(int n, int t, vector<int> &arr, int baseAmount){
    int totalAmount = 0;
    for(int wt : arr){
        if(wt > t){
            totalAmount += (2*baseAmount);
        }
        else{
            totalAmount += baseAmount; 
        }
    }
    return totalAmount;
}
int solve2(int n, int t, vector<int> &arr, int baseAmount){
    int totalAmount = 0;
    for(int wt : arr){
        if(wt > t){
            totalAmount += baseAmount;
            totalAmount += (wt-t);
        }
        else{
            totalAmount += baseAmount;
        }
    }
    return totalAmount;
}
int main()
{
    int n,t,x, baseAmount;
    cin>>n>>t;
    vector<int> weights;
    for(int i = 0; i<n; i++){
        cin>>x;
        weights.push_back(x);
    }
    baseAmount = 1;
    cout<<solve(n,t,weights, baseAmount)<<endl;
    cout<<solve2(n, t, weights, baseAmount)<<endl;
    return 0;
}
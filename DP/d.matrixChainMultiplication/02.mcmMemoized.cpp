//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int t[101][101];

//T - O(n*n*n) ..for every time (n^2), we run a somewhat n loop 
//S - O(n*n) + O(n) - ass

int solve(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }
    if(t[i][j] != -1)   return t[i][j];
    int ans = INT_MAX;
    for(int k = i;k<=j-1; k++){
        int tempans = solve(arr,i,k)+solve(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);
        ans = min(ans,tempans);
    }
    return t[i][j] = ans;
}
int matrixMultiplication(int n, int arr[])
{
    // i = 1, j = n-1
    memset(t,-1,sizeof(t));
    return solve(arr,1,n-1);
}
int main()
{   
    int arr[100];
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<matrixMultiplication(n,arr)<<endl;
    return 0;
}
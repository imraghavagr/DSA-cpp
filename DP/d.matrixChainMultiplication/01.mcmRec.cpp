#include<iostream>
#include<climits>
using namespace std;
int solve(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }
    int ans = INT_MAX;
    for(int k = i;k<=j-1; k++){
        int tempans = solve(arr,i,k)+solve(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);
        ans = min(ans,tempans);
    }
    return ans;
}
int matrixMultiplication(int n, int arr[])
{
    // i = 1, j = n-1
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
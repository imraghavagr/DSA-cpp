#include<iostream>
using namespace std;
int subsetSum(int* arr, int N, int sum){
    
    //space optimized code 
    vector<int> dp(sum+1, 0);
    
    for(int i = 1; i<=N; i++){
        for(int j = sum; j>=1; j--){
            dp[0] = 1;
            if(arr[i-1]<=j){
                //two choices - take, dont take 
                dp[j] = dp[j-arr[i-1]] || dp[j];
            }
        }
    }
    return dp[sum];
}
int equalPartition(int N, int arr[])
{
    // code here
    long long sum = 0;
    for(int i = 0; i<N; i++){
        sum += arr[i];
    }
    if(sum&1){
        //means sum is odd 
        return 0;
    }
    else{
        //sum is even 
        return subsetSum(arr, N, sum/2);
    }
}
int main()
{
    return 0;
}
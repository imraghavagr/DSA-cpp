//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
//given an array, return true/1 if that array can be divided into two unique subsets with equal sum.
#include<iostream>
using namespace std;

int subsetSum(int arr[], int N, int sum){
    int t[N+1][sum+1];
    //initialization
    for(int i = 0; i<N+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i==0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j] = 1;
            }
        }
    }
    //filling remaining elements
    for(int i = 1; i<N+1; i++){
        for(int j = 1; j<sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[N][sum];
}
int equalPartition(int N, int arr[])
{
    int sum = 0; //make it long or long long if the inputs are large
    for(int i = 0; i<N; i++){
        sum += arr[i];
    }
    
    if(sum&1){
        //meas sum is odd- which means it is not possible to divide this array into two equal sum subsets
        return 0;
    }
    else{
        //sum is even 
        //now we simply need to check if there exists a subset with sum = sum /2. 
        //because if one subset has sum = sum/2 then obviously other subset(remainnig elements) will also have sum = sum/2
        return subsetSum(arr,N,sum/2);
    }
}
int main()
{
    int arr[] = {1,5,11,5};
    int n = sizeof(arr)/sizeof(int);
    int ans = equalPartition(n,arr);
    if(ans == 1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
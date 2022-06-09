/*Given an integer array arr of size N, the task is to divide it into two sets S1
 and S2 such that the absolute difference between their sums is minimum and 
 find the minimum difference

    Input: N = 4, arr[] = {1, 6, 11, 5} 
    Output: 1
    Explanation: 
    Subset1 = {1, 5, 6}, sum of Subset1 = 12 
    Subset2 = {11}, sum of Subset2 = 11  , s2-s1 =1 that is minimum

gfg: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#
*/
#include<iostream>
#include<climits>
using namespace std;

int minDifference(int arr[], int n)  { 
    // Your code goes here
    
    int range = 0;
    for(int i = 0; i<n; i++){
        range+=arr[i];
    }
    //range is basically sum of arr
    //we need to minimize |s2-s1|
    
    //s1 - range of s1 = 0 to sum/2 
    //s2 - |range-s1| 
    //|s2-s1| becomes |range-s1-s1| = |range-2s1|
    
    //now the first task in hand is to find the candidates for s1 using subset sum problem
    int t[n+1][(range/2)+1]; // s1<s2, therefore s1 0 to range/2 me hii lie karega 
    //initialization
    int sum = range/2;
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i==0){
                t[i][j] = false;
            }
            if(j==0){
                t[i][j] = true;
            }
        }
    }
    //filling remaining cells of t
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            if(arr[i-1]<=j){
                t[i][j] =  t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    // //now the values of sum for which the last row of t is true are only the candidates for s1
    // vector<int> v;
    // for(int j = 0; j<sum+1; j++){
    //     if(t[n][j]){
    //         v.push_back(j);
    //     }
    // }
    // //now v contains all possible candidates for s1
    // int ans = INT_MAX;
    // for(int i = 0; i<v.size(); i++){
    //     ans = min(ans, abs(range-2*v[i]));
    // }

    //above approach is also fine,, below is more space optimized as we do not need to create the vector

    int ans = INT_MAX;
	for(int j = 0; j<sum+1; j++){
	    if(t[n][j]){
	        ans = min(ans, abs(range-2*j));
	    }
	}
	return ans;
} 

int main()
{
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr)/sizeof(int);
    cout<<minDifference(arr,n)<<endl;
    return 0;
}

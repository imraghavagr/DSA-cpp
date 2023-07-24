#include<iostream>
using namespace std;
bool isPossible(int mid, vector<int> &nums, int k){
    //can nums be divided into k subarrays, s.t. the maximum sum of anny 
    //subarray is <= mid 
    int sum = 0; 
    int numSplits = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] > mid)   return false; 
        sum += nums[i];
        if(sum > mid){
            numSplits++; 
            sum = nums[i];
        }   
        if(numSplits > k-1) return false;
    }
    return numSplits <= k-1;
}
int splitArray(vector<int>& nums, int k) {
    int start = 0; 
    int end = accumulate(nums.begin(), nums.end(), 0);
    int totalSum = end; 
    int ans = -1; 
    while(start <= end){
        int mid = start + (end-start)/2; 
        if(isPossible(mid, nums, k)){
            ans = mid; 
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    return 0;
}
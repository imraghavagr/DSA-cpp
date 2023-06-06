#include<iostream>
using namespace std;

//brute force - O(n^2) time, O(1) space
int maxLen(vector<int>&A, int n)
{   
    int longestLen = 0;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += A[j];
            if(sum == 0){
                longestLen = max(longestLen, (j-i+1));
            }
        }
    }
    return longestLen;
}

//also works with negatives and zeros in the array 
//Better solution using hashing - O(n) time, O(n) space : given we use unordered_map and there are no collisions 
int getLongestSubarray(vector<int>& nums, int k){
    long long sum = 0;
    unordered_map<long long,int> mp;
    int maxLen = 0;
    for(int i = 0; i<nums.size(); i++){
        sum += nums[i];
        if(sum == k){
            maxLen = max(maxLen,i+1);
        }
        if(mp.find(sum-k) != mp.end()){
            maxLen = max(maxLen, i-mp[sum-k]);
        }
        //mp me sum ki value agar nahi hogi to hii daalenge .. update nahi karenge 
        //because we want to find the left farthest point where we are getting sum-k
        if(mp.find(sum) == mp.end())    mp[sum] = i;
    }
    return maxLen;
}

//Only works for all positive elements 
//sliding window or two pointer approach 
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int i = 0, j = 0;
    long long sum = 0;
    int maxLen = 0;
    while(j<a.size()){
        sum += a[j];
        if(sum < k){
            j++;
        }
        else if(sum == k){
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        else{
            //this means sum exceeds k 
            while(sum > k){
                sum -= a[i];
                i++;
            }
            if(sum == k)    maxLen = max(maxLen, j-i+1);
            j++;
        }
    }
    return maxLen;
}
int main()
{
    return 0;
}
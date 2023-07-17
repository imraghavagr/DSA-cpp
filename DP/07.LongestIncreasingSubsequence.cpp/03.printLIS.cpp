//another 1d dp based approach for finding lis 
#include<iostream>
using namespace std;

//O(n^2) time 
//O(n) space 
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(nums[j]<nums[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int ans = 1;
    // return the maximum of dp array 
    for(int num : dp)   ans = max(ans, num);
    return ans;
}

//Print LIS
vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int lastIdx = 0, ansLen = 1; 
    for(int i = 0; i<n; i++){
        hash[i] = i; 
        for(int j = 0; j<i; j++){
            if(arr[j] < arr[i] && 1+dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
            if(dp[i] > ansLen){
                ansLen = dp[i];
                lastIdx = i;
            }
        }
    }
    int j = ansLen-1;
    vector<int> ans(ansLen,0);
    ans[j--]  = arr[lastIdx];
    while(hash[lastIdx] != lastIdx){
        lastIdx = hash[lastIdx];
        ans[j--] = arr[lastIdx];
    }
    // reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    return 0;
}
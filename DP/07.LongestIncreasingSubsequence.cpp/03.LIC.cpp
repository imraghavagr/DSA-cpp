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


int main()
{
    return 0;
}
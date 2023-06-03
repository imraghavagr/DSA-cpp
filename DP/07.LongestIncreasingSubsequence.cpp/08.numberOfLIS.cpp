#include<iostream>
using namespace std;
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    int lisLen = 1;
    vector<int> dp(n, 1), cnt(n, 1);
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(nums[i] > nums[j]){
                if(dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                }
                else if(dp[i] == 1 + dp[j]){
                    cnt[i] += cnt[j];
                }
            }
        }
        lisLen = max(lisLen, dp[i]);
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(dp[i] == lisLen) ans += cnt[i];
    }
    return ans;
}
int main()
{
    return 0;
}
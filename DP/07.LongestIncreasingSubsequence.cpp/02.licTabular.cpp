#include<iostream>
using namespace std;

//tabular
int lengthOfLIS(vector<int>& nums) {
    vector<vector<int>> dp (nums.size()+1, vector<int>(nums.size()+1, 0));
    int n = nums.size();
    for(int i = n-1; i>=0; i--){
        for(int prev = i-1; prev>=-1; prev--){
            int len = 0 + dp[i+1][prev+1];
            if(prev == -1 || nums[i] > nums[prev]){
                len = max(len, 1+dp[i+1][i+1]);
            }
            dp[i][prev+1] = len;
        }
    }
    return dp[0][0];
}

//space optimized 
int lengthOfLIS(vector<int>& nums) {
    vector<int> ahead(nums.size()+1, 0);
    vector<int> curr(nums.size()+1, 0);
    int n = nums.size();
    for(int i = n-1; i>=0; i--){
        for(int prev = i-1; prev>=-1; prev--){
            int len = 0 + ahead[prev+1];
            if(prev == -1 || nums[i] > nums[prev]){
                len = max(len, 1+ahead[i+1]);
            }
            curr[prev+1] = len;
        }
        ahead = curr;
    }
    return ahead[0];
}
int main()
{
    return 0;
}
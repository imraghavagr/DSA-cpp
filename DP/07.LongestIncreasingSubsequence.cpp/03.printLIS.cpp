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
vector<int> printLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    vector<int> hash(n);
    int maxi = 1; 
    int lastIndex = 0;
    //O(n^2)
    for(int i = 0; i<n; i++){
        hash[i] = i;
        for(int j = 0; j<i; j++){
            if(nums[j]<nums[i]) && 1+dp[j] > dp[i]{
                dp[i] = dp[j]+1;
                hash[i] = j;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> temp(maxi);
    //O(len of LIS)
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
int main()
{
    return 0;
}
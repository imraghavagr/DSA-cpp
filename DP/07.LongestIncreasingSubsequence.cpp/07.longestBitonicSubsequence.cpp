#include<iostream>
using namespace std;
int LongestBitonicSequence(vector<int>nums)
{
    int n = nums.size();
    vector<int> dp1(n, 1), dp2(n, 1);
    
    //find lis from left to right 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(nums[i] > nums[j]){
                dp1[i] = max(dp1[i], 1+dp1[j]);
            }
        }
    }
    
    //find lis from right to left
    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>i; j--){
            if(nums[i] > nums[j]){
                dp2[i] = max(dp2[i], 1+dp2[j]);
            }
        }
    }
    
    int ans = 1;
    
    for(int i = 0; i<n; i++){
        ans = max(ans, dp1[i]+dp2[i]);
    }
    return ans-1;
}
int main()
{
    return 0;
}
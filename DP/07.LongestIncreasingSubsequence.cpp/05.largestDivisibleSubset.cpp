#include<iostream>
using namespace std;

//O(nlogn) time, O(1) space

// sort the array - so that instead of largest divisible subset, we can find largest divisible subsequence (because subset is asked, therefore any configuration will be accepted)
// instead of longest increasing subsequence, find longest divisible subsequence 
// print it using backtracking 
vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), 1);
    vector<int> hash(nums.size());

    int maxLen = 1;
    int lastIndex = 0;
    for(int i = 0; i<nums.size(); i++){
        hash[i] = i;
        for(int j = 0; j<i; j++){
            if(nums[i]%nums[j] == 0 && 1+dp[j] > dp[i]){
                dp[i] = 1+dp[j];
                hash[i] = j;
            }
        }
        if(maxLen < dp[i]){
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    //now backtrack from the lastIndex to the first index of ans 
    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);            
    }
    //since subset is asked, order does not matter, therefore no need to reverse it also 
    // reverse(temp.begin(), temp.end());
    return temp;
    }
int main()
{
    return 0;
}
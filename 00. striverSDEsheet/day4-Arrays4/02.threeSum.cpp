//https://leetcode.com/problems/3sum/description/
#include<iostream>
using namespace std;
//use two pointer to solve in o(n2). 
//we are asked for unique triplets.. so we will be needing set .. but that will give MLE and or TLE
//so we will handle this unique triplets case in two pointer code 
void twoSum(vector<int> nums, int s, int target, vector<vector<int>> &ans){
    int left = s; 
    int right = nums.size()-1;
    while(left<right){
        if(nums[left] + nums[right] == target){
            ans.push_back({nums[s-1], nums[left++], nums[right--]});
            //for skipping duplicate triples 
            while(left < right && nums[left] == nums[left-1]){
                left++;
            }
        }
        else if(nums[left] + nums[right] > target)  right--;
        else    left++;
    }
}
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    //no triplet can be formed if array size is less than 3 
    if(nums.size()<3)    return ans;
    sort(nums.begin(), nums.end());
    //if there is no negative element, sum 0 is not possible, so return null
    if(nums[0] > 0) return ans;
    int target = 0;
    for(int i = 0; i<nums.size()-2; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int remainingTarget = -1*nums[i];
        //now search for two elements that sum up to the remainingTarget in the array i+1 to last 
        twoSum(nums, i+1, remainingTarget, ans);
    }
    return ans;
}
int main()
{
    return 0;
}
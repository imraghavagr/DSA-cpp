//https://leetcode.com/problems/3sum/
#include<iostream>
using namespace std;

//no sorting + hash set approach - O(n)
void twoSum(vector<int> &nums, int s, int target, set<vector<int>> &tripletSet){
    unordered_set<int> st;
    vector<int> v;
    for(int i = s; i<nums.size(); i++){
        int r = target - nums[i];
        if(st.find(r) != st.end()){
            v = {nums[s-1], nums[i], r};
            sort(v.begin(), v.end());
            tripletSet.insert(v);
        }
        st.insert(nums[i]);
    }
}
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> triplets;
    set<vector<int>> tripletSet;    
    for(int i = 0; i<nums.size()-2; i++){
        int remTarget = 0 - nums[i];
        //find if remTarget exists using twoSum function
        twoSum(nums,i+1, remTarget, tripletSet);
    }
    for(auto it : tripletSet){
        triplets.push_back(it);
    }
    return triplets;
}
//optimal 
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans; 
    sort(nums.begin(), nums.end());
    for(int i = 0; i<nums.size()-2; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1, k = nums.size()-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum > 0){
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1])    j++;
                while(j<k && nums[k] == nums[k+1])  k--;
            }
        }
    }
    return ans;
}
int main()
{
    return 0;
}
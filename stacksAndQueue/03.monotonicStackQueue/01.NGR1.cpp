//https://leetcode.com/problems/next-greater-element-i/
#include<iostream>
using namespace std;
void NGR(vector<int> &nums, unordered_map<int,int> &mp){
    stack<int> stk; 
    for(int i = nums.size()-1; i>=0; i--){
        if(stk.empty()){
            mp[nums[i]] = -1;
        }
        else if(stk.top() > nums[i]){
            mp[nums[i]] = stk.top();
        }
        else{
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }
            if(stk.empty()) mp[nums[i]] = -1;
            else    mp[nums[i]] = stk.top();
        }
        stk.push(nums[i]);
    }
}
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //firstly we need to find NGR for each element in nums2 and store it in map
    unordered_map<int,int> mp; 
    NGR(nums2,mp);
    vector<int> ans;
    for(int num : nums1){
        ans.push_back(mp[num]);
    }
    return ans;
}
int main()
{
    return 0;
}
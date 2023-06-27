//https://leetcode.com/problems/next-greater-element-ii/description/
#include<iostream>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> stk; 
    vector<int> ans(n);
    for(int i = 2*n-1; i>=0; i--){
        if(stk.empty()){
            ans[i%n] = -1;
        }
        else if(nums[stk.top()] > nums[i%n]){
            ans[i%n] = nums[stk.top()];
        }
        else{
            while(!stk.empty() && nums[stk.top()] <= nums[i%n]){
                stk.pop();
            }
            if(stk.empty()) ans[i%n] = -1;
            else    ans[i%n] = nums[stk.top()];
        }
        stk.push(i%n);
    }
    return ans;
}
int main()
{
    return 0;
}
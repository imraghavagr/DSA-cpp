//https://leetcode.com/problems/subsets-ii/description/
#include<iostream>
using namespace std;
//without using set - optimal solution - like combination sum 2 problem as taught by striver
void solve(int index, vector<int> &nums, vector<int> &op, vector<vector<int>> &ans){
    if(index > nums.size()) return;
    ans.push_back(op);
    for(int i = index; i<nums.size(); i++){
        if(i>index && nums[i] == nums[i-1]) continue;
        op.push_back(nums[i]);
        solve(i+1, nums, op, ans);
        op.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> op;
    sort(nums.begin(), nums.end());
    solve(0, nums, op, ans);
    return ans;
}
// void solve(vector<int> ip, vector<int> op, set<vector<int>> &st){

//     //base case
//     if(ip.size() == 0) {
//         st.insert(op);
//         return;
//     }

//     vector<int> op1 = op;
//     vector<int> op2 = op;
    
//     //two choices b - take the element or do not take the element
//     op1.push_back(ip[0]);
//     //make input smaller 
//     ip.erase(ip.begin()+0);
//     solve(ip, op1, st);
//     solve(ip, op2, st);
// }
// vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//     vector<vector<int>> ans;
//     set<vector<int>> st;
//     vector<int> op; 
//     sort(nums.begin(), nums.end());
//     solve(nums, op, st);
//     for(auto it : st){
//         ans.push_back(it);
//     }
//     return ans;
// }
int main()
{
    return 0;
}

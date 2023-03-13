//https://leetcode.com/problems/subsets-ii/description/
#include<iostream>
using namespace std;
void solve(vector<int> ip, vector<int> op, set<vector<int>> &st){

    //base case
    if(ip.size() == 0) {
        st.insert(op);
        return;
    }

    vector<int> op1 = op;
    vector<int> op2 = op;
    
    //two choices b - take the element or do not take the element
    op1.push_back(ip[0]);
    //make input smaller 
    ip.erase(ip.begin()+0);
    solve(ip, op1, st);
    solve(ip, op2, st);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    set<vector<int>> st;
    vector<int> op; 
    sort(nums.begin(), nums.end());
    solve(nums, op, st);
    for(auto it : st){
        ans.push_back(it);
    }
    return ans;
}
int main()
{
    return 0;
}

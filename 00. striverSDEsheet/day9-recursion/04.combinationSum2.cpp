//https://leetcode.com/problems/combination-sum-ii/description/
#include<iostream>
using namespace std;
//Approach 1 - using set
// void solve(int index, vector<int> &ip, vector<int> &op, int target,
// set<vector<int>> &st){
//     if(target == 0 && index == ip.size()) {
//         st.insert(op);
//         return;
//     }
//     if(index == ip.size())  return;

//     if(ip[index] <= target){
//         //two choices - pick or skip 
//         op.push_back(ip[index]);
//         solve(index+1, ip, op, target-ip[index], st);
//         op.pop_back();

//         //not pick 
//         solve(index+1, ip, op, target, st);
//     }
//     else{
//         solve(index+1, ip, op, target, st);
//     }
// }
// vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//     vector<vector<int>> ans;
//     vector<int> op;
//     set<vector<int>> st;
//     sort(candidates.begin(), candidates.end());
//     solve(0, candidates,op, target, st);
//     for(auto it : st)   ans.push_back(it);
//     return ans;
// }

//Optimal approach - not generating duplicate subests
void solve(int index, vector<int> ip, vector<int> op, int target,
vector<vector<int>> &ans){

    if(index > ip.size())  return;
    if(target == 0){
        ans.push_back(op);
        return;
    }

    //for picking an element for current place, we will consider picking 
    //all the elements from current i to n;
    
    for(int j = index; j<ip.size(); j++){
        if(j > index && ip[j] == ip[j-1])    continue;
        //now lets see if we can pick this element or not 
        if(ip[j] <= target){
            vector<int> op1 = op;
            op1.push_back(ip[j]);
            solve(j+1, ip, op1, target-ip[j], ans);
        }
        else     break;
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    int index = 0;
    vector<int> op;
    vector<vector<int>> ans;
    solve(index, candidates, op, target, ans);
    return ans;
}
int main()
{
    return 0;
}
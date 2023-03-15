//https://leetcode.com/problems/combination-sum-ii/description/
#include<iostream>
using namespace std;
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
#include<iostream>
using namespace std;
void solve(vector<int> ip, vector<int> op, int target, vector<vector<int>> &ans){
    
    if(target == 0 && ip.size() == 0){
        ans.push_back(op);
    }
    
    if(ip.size() == 0){
        return;
    }

    if(ip[0] <= target){
        //two choices - pick or not pick
        vector<int> op1 = op;
        vector<int> op2 = op;
        op1.push_back(ip[0]);
        solve(ip, op1, target-ip[0], ans);
        ip.erase(ip.begin()+0);
        solve(ip, op2, target, ans);
    }
    else{
        //only one choice - do not pick 
        vector<int> op2 = op;
        ip.erase(ip.begin()+0);
        solve(ip, op2, target, ans);
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> op;
    solve(candidates, op, target, ans);
    return ans;
}
int main()
{
    return 0;
}
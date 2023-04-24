#include<iostream>
#include<vector>
using namespace std;
void solve(int idx, vector<int> &ip,vector<int> &op, int r, vector<vector<int>> &ans)
{
    if(op.size() == r){
        ans.push_back(op);
        return;
    }
    if(idx >= ip.size())    return;

    //pick or not pick 
    op.push_back(ip[idx]);
    solve(idx+1, ip, op, r, ans);
    op.pop_back();

    solve(idx+1, ip, op, r, ans);
}
int main()
{
    vector<int> v = {1,2,3,4,5};
    int r = 3;
    vector<vector<int>> ans;
    vector<int> op;
    solve(0, v,op,r,ans);
    for(auto it : ans){
        for(int x : it) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
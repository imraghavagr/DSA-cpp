#include<iostream>
using namespace std;
void solve(int n, string op, int o, int z, vector<string> &ans){
    if(o+z == n){
        ans.push_back(op);
        return;
    }
    if(o == z){
        //we have only 1 choice to use a 1 
        string op1 = op;
        op1.push_back('1');
        solve(n,op1,o+1,z,ans);
    }
    else{
        string op1 = op;
        string op2 = op;
        op1.push_back('1');
        op2.push_back('0');
        solve(n,op1,o+1, z, ans);
        solve(n,op2,o,z+1, ans);
    }
}
vector<string> NBitBinary(int N)
{   
    
    vector<string> ans;
    string op = "";
    int onesUsed = 0;
    int zerosUsed = 0;
    solve(N, op, onesUsed, zerosUsed, ans);
    return ans;
}
int main()
{   
    int n;
    cin>>n;
    solve(n);
    return 0;
}
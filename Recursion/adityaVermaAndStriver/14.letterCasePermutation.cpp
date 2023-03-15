#include<iostream>
using namespace std;
void solve(string ip, string op,  vector<string> &ans){
    //base case
    if(ip.length() == 0){
        ans.push_back(op);
        return;
    }
    //two cases -
    if(isdigit(ip[0])){
        //1. ip[0] is a digit 
        //simply take the digit
        string op_ = op;
        op_.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip, op_, ans);
    }
    else{
        //2. ip[0]  is a char 
        //two choices 
        string op1 = op;
        string op2 = op;
        op1.push_back(toupper(ip[0]));
        op2.push_back(tolower(ip[0]));
        //make input smaller 
        ip.erase(ip.begin()+0);
        solve(ip, op1, ans);
        solve(ip, op2, ans);      
    }
    
}
vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    string op;
    solve(s, op, ans);
    return ans;
}
int main()
{   

    return 0;
}
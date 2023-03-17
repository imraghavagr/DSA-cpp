#include<iostream>
#include<string>
using namespace std;
void solve(string ip, string op){
    if(ip.length() == 0){
        cout<<op<<" ";
        return;
    }

    
    for(int i = 0; i<ip.length(); i++){
        string op1 = op;
        string dummyIp = ip;
        op1.push_back(dummyIp[i]);
        dummyIp.erase(dummyIp.begin()+i);
        // cout<<dummyIp<<" ";
        solve(dummyIp, op1);
    }
}
//method 2
void solve2(vector<int> nums, int index, vector<vector<int>> &ans){
    if(index == nums.size()){
        ans.push_back(nums);
    }
    for(int i = index; i<nums.size(); i++){
        //swap value at index with all i 
        swap(nums[index], nums[i]);
        solve(nums, index+1, ans);
    }
}
int main()
{       
    string s;
    cin>>s;
    string op = "";
    solve(s, op);
    cout<<endl;
    return 0;
} 
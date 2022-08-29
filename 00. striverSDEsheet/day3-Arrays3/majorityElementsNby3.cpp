#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// using map  -O(n) time , O(1) space 
//below function accepts the vector nums and returns a vector of all majority elements present
vector<int> majorityElement1(vector<int>& nums) {
    //we can not make a freq array here:
    //1. range of nums[i]  is large
    //2. nums[i] also contains negative numbers
    vector<int> ans;
    //therefor using unordered_maps
    int majority = nums.size()/3;
    unordered_map<int,int> mp;//elem,freq
    for(int i = 0; i<nums.size(); i++){
        mp[nums[i]]++;
    }
    for(auto x : mp){
        if(x.second>majority)   ans.push_back(x.first);
    }
    return ans;
}
// // optimal - using extension of Moore's Voting Algo
// vector<int> majorityElement2(vector<int>& nums) {

// }

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)cin>>v[i];
    cout<<majorityElement2(v)<<endl;
    return 0;
}
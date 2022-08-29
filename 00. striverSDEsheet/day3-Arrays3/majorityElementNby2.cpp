#include<iostream>
#include<vector>
using namespace std;

// using map
int majorityElement1(vector<int>& nums) {
    //we can not make a freq array here:
    //1. range of nums[i]  is large
    //2. nums[i] also contains negative numbers

    //therefor using unordered_maps
    int majority = nums.size()/2;
    unordered_map<int,int> mp;//elem,freq
    for(int i = 0; i<nums.size(); i++){
        mp[nums[i]]++;
        if(mp[nums[i]]> majority){
            return nums[i];
        }
    }
    return -1;
}
// optimal - using moore's voting algo
int majorityElement2(vector<int>& nums) {
    int cnt = 0,elem = 0;
    for(int i = 0; i<nums.size(); i++){
        if(cnt == 0){
            elem = nums[i];
        }
        if(elem == nums[i]){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    return elem;
}

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)cin>>v[i];
    cout<<majorityElement2(v)<<endl;
    return 0;
}
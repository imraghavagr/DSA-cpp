//https://leetcode.com/problems/find-the-duplicate-number/
//cyclic sort question
#include<iostream>
#include<vector>

using namespace std;

int findDuplicate(vector<int>& nums) {

    int i = 0;
    while(i<nums.size()){
        int correctIdx = nums[i] -1;
        if(i !=  correctIdx && nums[correctIdx] != nums[i]){
            swap(nums[i], nums[correctIdx]);
        }
        else{
            i++;
        }
    }
    return nums[nums.size()-1];
}

int main(){
    
    vector<int> v{1,3,4,2,2};
    int ans = findDuplicate(v);
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}
//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
//cyclic sort question
#include<iostream>
#include<vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
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
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] != i+1){
            ans.push_back(i+1);
        }
    }
    return ans;
}

int main(){
    
    vector<int> v{1,1};
    vector<int> ans = findDisappearedNumbers(v);
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<endl;


    return 0;
}
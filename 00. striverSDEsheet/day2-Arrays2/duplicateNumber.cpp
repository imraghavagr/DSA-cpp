//https://leetcode.com/problems/find-the-duplicate-number/
#include<iostream>
#include<vector>
using namespace std;
 
//Cyclic sort concept
int findDuplicate(vector<int>& nums) {
    int i = 0;
    while(i<nums.size()){
        int ci = nums[i] - 1;
        if(ci != i && nums[ci] != nums[i]){
            swap(nums[ci],nums[i]);
        }
        else{
            i++;
        }
    }
    // for(int x:nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    
    //at last the duplicate number will be left untouched at the end of the array
    return nums[nums.size()-1];

}
int main()
{   
    vector<int> nums = {1,3,4,2,2};
    cout<<findDuplicate(nums)<<endl;
    return 0;
}
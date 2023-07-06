//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include<iostream>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(nums.size()==1)  return 1;
    //we  will maintains two pointers - read and write 
    int read = 1;
    int write  = 1;
    for(int i = 1; i<nums.size(); i++){
        if(nums[read] == nums[read-1]){
            read++;
        }
        else{
            nums[write] = nums[read];
            read++;
            write++;
        }
    }
    return  write;
}
int main()
{
    return 0;
}
//https://leetcode.com/problems/search-in-rotated-sorted-array/
#include<iostream>
using namespace std;
int search(vector<int> &nums, int s, int e, int target){
    while(s<=e){
        int mid = s + (e-s)/2;
        if(nums[mid] == target) return mid;
        if(target > nums[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return -1;
}
int findPivot(vector<int> &nums){
    int s = 0;
    int e = nums.size()-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        int prev = (mid+nums.size()-1)%nums.size();
        if(nums[mid] < nums[prev]){
            return mid;
        }
        if(nums[mid] >= nums[0]){
            s = mid + 1;
        }
        else{
            e = mid-1;
        }
    }
    return -1;
}
int search(vector<int>& nums, int target) {
    //fist we will find the index of the pivot element 
    int pivot = findPivot(nums);
    // cout<<pivot<<endl;
    //if pivot = -1, this means the array is not rotated
    if(pivot == -1) return search(nums, 0, nums.size()-1, target);

    //else first find in the left sorted part 
    int idx = search(nums, 0, pivot-1, target);
    if(idx != -1)   return idx;
    return search(nums, pivot, nums.size()-1, target);
}
int main()
{
    return 0;
}
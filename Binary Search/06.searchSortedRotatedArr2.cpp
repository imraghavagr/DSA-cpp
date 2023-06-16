#include<iostream>
using namespace std;
//this time the elements of the array are not necesserily unique.. it may contain duplicate elements 
bool search(vector<int>& nums, int target) {
    int s = 0, e = nums.size()-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(nums[mid] == target) return true;
        if(nums[s] == nums[mid] && nums[mid] == nums[e]){
            s++;
            e--;
            continue;
        }
        if(nums[mid] >= nums[s]){
            //left part is sorted
            if(target >= nums[s] && target <=  nums[mid])  e = mid-1;
            else    s = mid + 1;
        }
        else{
            //right part is sorted 
            if(target >= nums[mid] && target <= nums[e])  s = mid + 1;
            else    e = mid - 1;
        }
    }
    return false;
}
int main()
{
    return 0;
}
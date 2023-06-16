#include<iostream>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)    return nums[0];
    if(nums[0] != nums[1])  return nums[0];
    if(nums[n-1] != nums[n-2])  return nums[n-1];

    //now we can start from 1 and end at n-2; 

    int s = 1, e = n-2; 

    while(s<=e){
        int mid = s + (e-s)/2;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
            return nums[mid];
        }
        if((mid % 2 == 0 && nums[mid] == nums[mid+1]) || 
            (mid % 2 == 1 && nums[mid] == nums[mid-1])){
            
            //we are standing on the left half, we will go to right by eliminating 
            //the left half
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return -1;
}
int main()
{
    return 0;
}
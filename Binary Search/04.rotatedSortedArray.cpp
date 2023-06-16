//A sorted array was right rotated k times, given the rotated version of the array, find k. 
#include<iostream>
using namespace std;
int findMin(vector<int>& nums) {
    int N = nums.size();
    if(N == 1 || nums[0] < nums.back()){
        //array is already sorted 
        return nums[0];
    }
    int s = 0, e = nums.size()-1;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        int prev = (mid+N-1)%N;
        int next = (mid+1)%N;
        if(nums[mid] < nums[prev] && nums[mid] < nums[next]){
            return nums[mid];
        }
        else if(nums[mid] < nums[0]){
            //this means, left is the unsorted part, and smallest element lies in the left 
            e = mid -1 ;
        }
        else{
            s = mid + 1;
        }
    }
    return -1;
}
int main()
{
    return 0;
}
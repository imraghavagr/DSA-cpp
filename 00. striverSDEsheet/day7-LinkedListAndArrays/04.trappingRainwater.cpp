#include<iostream>
using namespace std;
//Better solution - O(N) time, O(N) space
int trap(vector<int>& height) {
    int ans = 0;
    vector<int> leftMax(height.size());
    vector<int> rightMax(height.size());
    
    //lets first compute the leftMax 
    leftMax[0] = height[0];
    for(int i = 1; i<height.size(); i++){
        leftMax[i] = max(leftMax[i-1],height[i]);
    }
    //now lets compute the rightMax
    rightMax[height.size()-1] = height.back();
    for(int i = height.size()-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1], height[i]);
    }
    //now lets compute the answer 
    for(int i = 0; i<height.size(); i++){
        ans += (min(leftMax[i], rightMax[i]) - height[i]);
    }
    return ans;
}
//Optimal solution - O(N) time O(1) space
int trap(vector<int>& nums) {
    int leftMax = 0;
    int rightMax = 0;
    int left = 0;
    int right = nums.size()-1;
    int totalWater = 0;
    while(left<=right){
        if(nums[left]<=nums[right]){
            //if the current building is leftMax 
            if(leftMax <= nums[left])   leftMax = nums[left];
            else    totalWater += leftMax-nums[left];
            left++;
        }
        else{
            if(rightMax <= nums[right]) rightMax = nums[right];
            else    totalWater += rightMax-nums[right];
            right--;
        }
    }
    return totalWater;
}
int main()
{
    return 0;
}
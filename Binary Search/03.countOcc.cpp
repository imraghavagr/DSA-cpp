#include<iostream>
using namespace std;
int findOcc(int target, vector<int> &nums, int flag){
	int ans = -1; 
	int s = 0, e = nums.size()-1;
	while(s<=e){
		int mid = s + (e-s)/2; 
		if(nums[mid] == target){
			ans = mid;
			if(flag)   s = mid + 1;
			else    e = mid - 1;
		}
		else if(target > nums[mid]) s = mid + 1;
		else    e = mid - 1;
	}
	return ans; 
}
int count(vector<int>& nums, int n, int target) {
	int fo = findOcc(target, nums,0);
	if(fo == -1)    return 0;
	int lo = findOcc(target, nums, 1);
	return lo-fo+1;
}
int main()
{
    return 0;
}
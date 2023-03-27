//https://leetcode.com/problems/max-consecutive-ones/description/
#include<iostream>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0;
    int currentConsecutive = 0;
    for(int i = 0; i<nums.size(); i++){
        if(i>0 && nums[i] == 1 && nums[i-1] == 1){
            currentConsecutive++;
        }
        else if(nums[i] == 1){
            currentConsecutive = 1;
        }
        else{
            currentConsecutive = 0;
        }
        ans = max(ans, currentConsecutive);            
    }
    return ans;
}
int main()
{
    return 0;
}
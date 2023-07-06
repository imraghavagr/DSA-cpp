//https://leetcode.com/problems/max-consecutive-ones/description/
#include<iostream>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int i = 0, j = 0; 
    int numZeros = 0; 
    int ans = 0; 
    while(j<nums.size()){
        if(nums[j] == 0)    numZeros++;
        if(numZeros == 0){
            ans = max(ans, j-i+1);
            j++;
        }
        else{
            while(numZeros > 0){
                if(nums[i] == 0)    numZeros--;
                i++;
            }
            j++;
        }
    }
    return ans;
}
int main()
{
    return 0;
}
//https://leetcode.com/problems/max-consecutive-ones-ii/description/?envType=study-plan-v2&envId=premium-algo-100
#include<iostream>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int ansLen = 1; 
    int i = 0, j = 0; 
    int numZeros = 0; 
    while(j < nums.size()){
        if(nums[j] == 0)    numZeros++;
        if(numZeros <= 1 ){
            ansLen = max(ansLen, j-i+1);
            j++;
        }
        else{
            while(numZeros > 1){
                if(nums[i] == 0)    numZeros --; 
                i++;
            }
            if(numZeros == 1)  ansLen = max(ansLen, j-i+1);
            j++;
        }
    }
    return ansLen;
}
int main()
{
    return 0;
} 
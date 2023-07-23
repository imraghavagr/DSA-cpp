#include<iostream>
using namespace std;
bool isPossible(int mid, vector<int> &nums, int threshold){
    int sum = 0;
    for(int num : nums){
        sum += ceil((float)num/mid);
        if(sum > threshold) return false;
    }
    return true;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int s = 1; 
    int e = *max_element(nums.begin(), nums.end());
    int ans = 0;
    while(s<=e){
        int mid = s + (e-s)/2; 
        if(isPossible(mid, nums, threshold)){
            ans = mid; 
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{
    return 0;
}
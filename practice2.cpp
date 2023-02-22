#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &nums, int mid, int k){
    //means we need to change elements from index 0 to mid-2 in less than k steps 
    int target = nums[mid-1];
    for(int i = 0; i<mid-1; i++){
        if(k>=target-nums[i]){
            k -= (target-nums[i]);
        }
        else{
            return false;
        }
    }
    return true;
}
bool isPossible(vector<int> &nums, int mid, int k){
    //check how many numbers we can convert in available k value 
    int targetValue = nums[mid-1];
    int convertedValues = 0;
    int i = 0;
    while(convertedValues < mid && k>=targetValue-nums[i] ){
        k -= targetValue-nums[i];
        i++;        
    }    
}
int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    // for(auto x : nums){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // cout<<nums[71]<<" "<<nums[72]<<" "<<nums[73]<<endl;
    int s = 1, e = nums.size();
    int ans = 1;
    while(s<=e){
        int mid = s + (e-s)/2;
        cout<<mid<<endl;
        if(isPossible(nums, mid, k)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966};
    
    int k = 3056;
    cout<<maxFrequency(v,k)<<endl;

    return 0;
}
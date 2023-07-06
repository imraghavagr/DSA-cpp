#include<iostream>
using namespace std;
void merge(vector<int> &nums, int s, int mid, int e, int &ans, vector<int> &temp){
    int r1 = s;
    int r2 = mid+1; 
    int w = s;
    int j = mid+1;

    for (int i = s; i <= mid; i++) {
        while (j <= e && nums[i] > (2 * (long long)nums[j])) {
            j++;
        }
        ans += (j - (mid + 1));
    }
    while(r1<=mid || r2<=e){
        if(r1>mid){
            temp[w++] = nums[r2++];
        }
        else if(r2>e){
            temp[w++] = nums[r1++];
        }
        else{
            temp[w++] = nums[r1]<nums[r2] ? nums[r1++]: nums[r2++];
        }
    }
    //copy back temp to the original array 
    for(int i = s; i<=e; i++){
        nums[i] = temp[i];
    }
}
void mergeSort(vector<int> &nums, int s, int e, int &ans, vector<int> &temp){
    if(s==e)    return;

    //divide
    int mid = s + (e-s)/2;
    mergeSort(nums, s, mid, ans, temp);
    mergeSort(nums, mid+1, e, ans, temp);

    //now merge back the sorted arrays 
    merge(nums, s, mid, e, ans, temp);
}
int reversePairs(vector<int>& nums) {
    //we will solve this using merge sort in nlogn time 
    int ans = 0;
    vector<int> temp(nums.size());
    mergeSort(nums, 0, nums.size()-1, ans, temp);
    return ans;
}
int main()
{
    return 0;
}
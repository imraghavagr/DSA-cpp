#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>& nums) {
        
    int v1 = -1;
    int v2;
    int n = nums.size();
    //step 1: Travesrse from back and find the index i where nums[i]<nums[i+1]
    for(int i = n-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            v1 = i;
            break;
        }
    }
    if(v1 == -1){
        //this means the given array is the largest permutation and it will not have 
        //next greater permutation.
        //so, reverse the array
        reverse(nums.begin(),nums.end());
        return;
    }
    
    //step2 : Again traverse the array in reverse and find the index in where arr[i]>arr[v1]
    for(int i = n-1; i>=0; i--){
        if(nums[i] > nums[v1]){
            v2 = i;
            break;
        }
    }
    
    //step 3: Swap
    swap(nums[v1],nums[v2]);
    
    //step 4: Reverse the array from v1+1 th index till last 
    reverse(nums.begin()+v1+1, nums.end());        
}

int main()
{
    vector<int> v = {1,3,2};
    nextPermutation(v);
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
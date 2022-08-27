//https://leetcode.com/problems/sort-colors/
#include<iostream>
#include<vector>
using namespace std;

//approach 1 - use any sorting algo, T - O(nlogn), space = O(1)

//approach 2 - O(N) time 
void sortColors(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0; 
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == 0)    count0++;
        else if(nums[i] == 1)   count1++;
        else    count2++;
    }
    int i = 0;
    while(count0>0){
        nums[i++] = 0;
        count0--;
    }
    while(count1>0){
        nums[i++] = 1;
        count1--;
    }
    while(count2>0){
        nums[i++] = 2;
        count2--;
    }
}

//apporach 3 - maintain 3 pointers - low, med, high
//This problem is a variation of the popular Dutch National flag algorithm 


int main()
{
    vector<int> v = {1,2,0,2,1,0};
    sortColors(v);
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
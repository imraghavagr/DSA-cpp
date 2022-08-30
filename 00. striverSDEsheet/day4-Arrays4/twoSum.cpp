//https://leetcode.com/problems/two-sum/
#include<iostream>
using namespace std;

//approach 1 - brute force O(n2)time O(1) spcace

//apporach 2 - sort the array and apply two pointer apporach
//since, here index of the values is asked therefore we would 
//need to store the original array before sorting .. 
//that's why space will be O(n), otherwise it have been O(1)
//time == O(nlogn)
 vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> ans,temp;
    temp = nums;
    sort(temp.begin(),temp.end());
    
    //two pointer approach 
    int i = 0;
    int j = nums.size()-1;
    int n1,n2;
    while(i<j){
        if(temp[i] + temp[j] == target){
            n1 = temp[i];
            n2 = temp[j];
            break;
        }
        else if(temp[i]+temp[j] < target){
            i++;
        }
        else{
            j--;
        }
    }
    //now lets find out the req indices from the values
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == n1){
            ans.push_back(i);
        }
        else if(nums[i] == n2){
            ans.push_back(i);
        }
    }
    return ans;
}

//approach 3 - Using hashmaps 
//time - O(n), space - O(n)
vector<int> twoSum3(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int,int> mp; // value, index
    for(int i = 0; i<nums.size(); i++){
        if(mp.find(target-nums[i]) == mp.end()){
            mp[nums[i]] = i;
        }
        else{
            ans.push_back(mp[target-nums[i]]);
            ans.push_back(i);
        }
    }
    return ans;
}


int main()
{
    return 0;
}
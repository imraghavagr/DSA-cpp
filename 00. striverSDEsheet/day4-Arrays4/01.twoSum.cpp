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
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp; //value, index 
    vector<int> ans;
    for(int i = 0; i<nums.size(); i++){
        int neededValue = target - nums[i];
        //tell that this value is present at this index
        if(mp.find(neededValue) != mp.end()){
            ans.push_back(mp[neededValue]);
            ans.push_back(i);
            return ans;
        }
        else    mp[nums[i]] = i;
    }
    return  ans;
}


//approach 4 - sort the array and apply binary search
int binarySearch(int key, vector<pair<int,int>> &arr, int i){
    int mid;
    int s = i+1; 
    int e = arr.size()-1;
    while(s<=e){
        mid = s + (e-s)/2;
        if(arr[mid].first == key){
            return mid;
        }
        else if(arr[mid].first > key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}
vector<int> twoSum4(vector<int>& nums, int target) {
    //binary search approach .. but we will need to sort the array first 
    vector<pair<int,int>> temp;
    for(int i = 0; i<nums.size(); i++){
        temp.push_back({nums[i], i});
    }
    sort(temp.begin(), temp.end());
    //now iterate the target array, and for current i, try to find 
    //target-nums[i] in the temp array from index i +1 to end 
    vector<int> ans;
    for(int i = 0; i<temp.size(); i++){
        int key = target-temp[i].first;
        //now use binary search to find 
        int idx = binarySearch(key, temp, i);
        if(idx != -1){
            ans.push_back(temp[i].second);
            ans.push_back(temp[idx].second);
        }
    }
    return ans;
}

int main()
{
    return 0;
}
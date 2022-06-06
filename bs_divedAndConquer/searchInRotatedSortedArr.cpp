#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> &nums, int s, int e, int target){
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                s = mid +1;
            }
            else{
                e = mid-1;
            }
        }
        return -1;
    }
    
    int findPivot(vector<int> &nums){
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            //4 cases
            if(mid<nums.size() and nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(mid>=0 and nums[mid] < nums[mid-1]){
                return mid-1;
            }
            else if(nums[s] >= nums[mid]){
                e = mid-1;
            }
            else if(nums[s] < nums[mid]){
                s = mid + 1;
            }
        }
        return -1; // this means it is a normal array with no rotation
    }
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        if(pivot == -1){
            return binarySearch(nums,0,nums.size()-1,target);
        }
        
        if(nums[pivot] == target) return pivot;
        
        //search in 1st part 
        int ans = binarySearch(nums,0,pivot-1,target);
        return ans !=-1 ? ans : binarySearch(nums,pivot+1,nums.size()-1,target);
    }
int main(){

    vector<int> arr{1};
    int target = 0;
    cout<<search(arr,target)<<endl;
    return 0;
}
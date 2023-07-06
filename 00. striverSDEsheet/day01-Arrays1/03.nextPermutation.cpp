//2 1 5 4 3 => 2 3 5 4 1 => 2 3 1 4 5
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>& nums) {
    //find the point from where increasing sequence is starting 
    int v1 = -1; 
    //find the breaking point where the increasing sequence from back stops 
    //i.e. find the first index i from right to left where nums[i] < nums[i+1]
    for(int i = nums.size()-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            v1 = i;
            break;
        }
    }
    if(v1 == -1){
        //input is the largest permuation, just reverse it and return 
        reverse(nums.begin(), nums.end());
        return;
    }        
    //find the smallest number larger than nums[v1] from v1 to end 
    //to find this we will do following 
    //because after index v1, we have a decreasing sequence, where all
    //nums are greater than nums[v1]
    //therefore we will just traverse from right to left 
    //and find the index v2, s.t. nums[v2] > nums[v1];
    //now find the first index from back v2, s.t. 
    int v2; 
    for(int i = nums.size()-1; i>=0; i--){
        if(nums[i] > nums[v1]){
            v2 = i; 
            break;
        }
    }
    //now to get the next permutation i.e. just larger than the curr permuation
    //we will first swap the number at index which is breaking point of increasing sequence from back and the smallest number from that index to end which is larger than nums[v1]        
    swap(nums[v1], nums[v2]);
    
    //now we will have to sort the later half i.e. from index v1 to v2 , 
    //because current nums[v1] ke baad smallest number aana chahiye to get next smaller permutation ..
    //therefore because after v1 we have a decreasing sequence, we can just reverse it to get the sorted order
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
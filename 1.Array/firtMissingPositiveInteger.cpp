#include<iostream>
#include<vector>
using namespace std;

int findMissing(vector<int> &nums){
    int i = 0;
    while(i<nums.size()){
        int correctIdx = nums[i] - 1;
        if(i !=  correctIdx && nums[i]<=nums.size() && nums[i]>0 && nums[i] != nums[correctIdx]){
            swap(nums[i], nums[correctIdx]);
        }
        else{
            i++;
        }
    }
    
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] != i+1){
            return i+1;
        }
    }
    return nums.size()+1;
}

int main(){

    vector<int> v{3,4,-1,1};
    cout<<findMissing(v)<<endl;
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
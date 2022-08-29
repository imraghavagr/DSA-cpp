//https://www.interviewbit.com/problems/repeat-and-missing-number-array/
#include<iostream>
#include<vector>
using namespace std;

//Cyclic sort concept
vector<int> solve(vector<int> &nums){
    int i = 0;
    while(i<nums.size()){
        int ci = nums[i] - 1;
        if(ci != i && nums[ci] != nums[i]){
            swap(nums[ci],nums[i]);
        }
        else{
            i++;
        }
    }
    vector<int> ans;
    for(int i = 0; i<nums.size(); i++){
        int ci = nums[i] - 1;
        if(i != ci){
            ans.push_back(nums[i]);
            ans.push_back(i+1);
            break;
        }
    }
    return ans;
}
int main()
{   
    vector<int> nums = {3,1,2,5,4,6,7,5};
    vector<int> ans = solve(nums);
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
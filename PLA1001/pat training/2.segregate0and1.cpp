#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int> &nums){
    int countZeros = 0;
    for(auto it : nums){
        if(it == 0) countZeros++;
    }
    cout<<countZeros<<endl;
    for(int i = 0; i<nums.size(); i++){
        if(i < countZeros)  nums[i] = 0;
        else nums[i] = 1;
    }
}
void solve2(vector<int> &nums){
    int i = 0; 
    int j = nums.size()-1;
    while(i<j){
        if(nums[i] == 0){
            i++;
        }
        else if(nums[j] == 1){
            j--;
        }
        else{
            swap(nums[i], nums[j]);
        }
    }
}
int main()
{   
    vector<int> nums;
    int n,x;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>x;
        nums.push_back(x);
    }
    // solve(nums);
    solve2(nums);
    for(auto it : nums) cout<<it<<" ";
    cout<<endl;

    return 0;
}

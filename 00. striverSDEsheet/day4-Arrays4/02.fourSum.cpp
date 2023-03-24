//https://leetcode.com/problems/4sum/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//function should return a 2D vector consisting of all possible answers as individual vectors.

//approach 1: Sort the array + take 3 pointers-i,j,k + use binary search to search for target-(arr[i]+arr[j]+arr[k]).
// Worst Case time complexity- O(nlogn + n^3 * logn) - nlogn for sorint, n3 for three nested loops and another logn for bs.
//T = O(N^3*LogN), Space = O(1)
vector<vector<int>> fourSum1(vector<int>& nums, int target) {
    set<vector<int>> st;
    //sort the given array
    sort(nums.begin(), nums.end());

    //find every possible combination of i,j,k
    for(int i = 0; i<nums.size(); i++){
        for(int j = i+1; j<nums.size(); j++){
            for(int k = j+1; k<nums.size(); k++){
                int x = (long long)target - ((long long)nums[i] + (long long)nums[j] + (long long)nums[k]);
                //search for x in the array using binary search
                if(binary_search(nums.begin()+k+1,nums.end(),x)){
                    //inbuilt binary search used.. will return true if x is found
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    temp.push_back(nums[x]);
                    // sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main()
{   
    vector<int> v = {2,2,2,2,2};
    int target = 8;
    vector<vector<int>> ans = fourSum1(v,target);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
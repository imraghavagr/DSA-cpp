#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//O(NLogN * N) ~ O(NLogN) time, O(n) space, where n<=N, n = size of output array
//nlogn for sorting and n for traversal
//OPTIMAL
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());    
    vector<vector<int>> ans;
    //iterate through the every pair in intervals
    ans.push_back(intervals[0]);
    for(int i = 1; i<intervals.size(); i++){
        //check if current interval merges with the last interval present in the ans vector.
        if(ans[ans.size()-1][1] >= intervals[i][0]){
            if(ans[ans.size()-1][1] < intervals[i][1]){
                //this is condition is to make sure the following merging does not happen
                //(1,4) (2,3) = (1,3)
                ans[ans.size()-1][1] = intervals[i][1];
            }            
        }
        else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}
//second approach with O(nlogn + N * N) -> O(N^2) time and O(1) space 
//vector.erase() operation will itself take O(N) time 
//instead of creating an extra ans array, update the original intervals array itself accordingly
vector<vector<int>> merge2(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());    
 
    //iterate through the every pair in intervals
    // ans.push_back(intervals[0]);
    for(int i = 1; i<intervals.size(); i++){
        //check if current interval merges with the last interval present in the ans vector.
        if(intervals[i-1][1] >= intervals[i][0]){
            if(intervals[i-1][1] < intervals[i][1]){
                //this is condition is to make sure the following merging does not happen
                //(1,4) (2,3) = (1,3)
                intervals[i-1][1] = intervals[i][1];
                
                //also erase the ith pair from intervals vector
                intervals.erase(intervals.begin()+i);
                i--;
            }
            else{
                intervals.erase(intervals.begin()+i);
                i--;
            }
        }
    }
    return intervals;
}
int main()
{
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    // vector<vector<int>> v = {{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
    // vector<vector<int>> v = {{1,4},{1,4}};

    vector<vector<int>> ans = merge1(v);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<2; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
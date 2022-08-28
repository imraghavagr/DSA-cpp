#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
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
int main()
{
    // vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> v = {{1,4},{2,3}};
    // vector<vector<int>> v = {{1,4},{0,2},{3,5}};

    vector<vector<int>> ans = merge(v);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<2; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
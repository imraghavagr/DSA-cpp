//https://leetcode.com/problems/k-closest-points-to-origin/description/
#include<iostream>
using namespace std;
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>> pq; //distance, index
    int i = 0;
    for(auto it : points){
        int x = it[0];
        int y = it[1];
        int distance = (x*x) + (y*y); // no need to perform sqrt while finding distance, because the relative ordering will be same.
        pq.push({distance, i});
        if(pq.size() > k)   pq.pop();
        i++;
    }
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ans.push_back(points[it.second]);
    }
    return ans;
}
int main()
{
    return 0;
}
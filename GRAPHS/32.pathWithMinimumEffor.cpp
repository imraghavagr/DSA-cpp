//https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort
#include<iostream>
using namespace std;
int MinimumEffort(vector<vector<int>>& heights) {
    // Code herepair<int,pair<int,int>>
    int m = heights.size(), n = heights[0].size();
    
    vector<vector<int>> distance(m, vector<int>(n,1e9));
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
    //push the start node into the queue 
    pq.push({0, {0,0}});
    //put distance from source to source as 0
    distance[0][0] = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int i = it.second.first;
        int j = it.second.second;
        int d = it.first;
        
        // we will check for destination while taking cell out of the pq, not while inserting
        if(i == m-1 && j == n-1){
            return d;
        }
        
        //go for all neighbours 
        int delR[] = {-1, 0, 1, 0};
        int delC[] = {0, 1, 0, -1};
        
        for(int k = 0; k<4; k++){
            int newR = i + delR[k];
            int newC = j + delC[k];
            if(newR>=0 && newC>=0 && newR<m && newC<n
                && max(d, abs(heights[i][j] - heights[newR][newC])) < distance[newR][newC]){
                
                distance[newR][newC] = max(d, abs(heights[i][j] - heights[newR][newC]));
                pq.push({max(d, abs(heights[i][j] - heights[newR][newC])), {newR, newC}});
            }
        }
    }
    // we can always reach destination from the source 
}
int main()
{
    return 0;
}
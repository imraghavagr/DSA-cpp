//https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph
#include<iostream>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Code here
    vector<pair<int,int>> adj[n+1];
    for(int i = 0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    //define a min heap 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    //push the start node with distance 0 into pq
    pq.push({0, 1});
    //define a dist array 
    vector<int> dist(n+1, INT_MAX);
    dist[1] = 0;
    //define a parent array for memoization/caching 
    vector<int> parent(n+1, -1);
    //1 came in from 1 because it is the starting node
    parent[1] = 1;
    
    while(!pq.empty()){
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        //check for all adj nodes 
        for(auto it : adj[node]){
            int adjNode = it.first;
            int adjW = it.second;
            if(dist[adjNode] > dis + adjW){
                pq.push({dis+adjW, adjNode});
                dist[adjNode] = dis + adjW;
                //adjNode came from node, update this 
                parent[adjNode] = node;
            }
        }
    }
    if(parent[n] == -1){
        //means it was unreachable 
        return {-1};
    }
    vector<int> ans;
    int node = n;
    ans.push_back(n);
    while(parent[node] != node){
        ans.push_back(parent[node]);
        node = parent[node];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    return 0;
}
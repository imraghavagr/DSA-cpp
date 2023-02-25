//https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance
#include<iostream>
using namespace std;
//only relaxation of edges required in case of undirected graph 
//it it would have been a directed graph, we would have first applied topo sort, then relaxation.
bool bfs(vector<int> adj[], vector<int> &dist, int src){
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while(!q.empty()){
        int n = q.front();
        q.pop();
        for(auto it : adj[n]){
            if(dist[n] + 1 < dist[it]){
                q.push(it);
                dist[it] = dist[n]+1;
            }
        }
    }
}
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // code here
    vector<int> adj[N];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> dist(N, INT_MAX);
    bfs(adj, dist, src);
    for(int i = 0; i<N; i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    return dist;
}
int main()
{
    return 0;
}
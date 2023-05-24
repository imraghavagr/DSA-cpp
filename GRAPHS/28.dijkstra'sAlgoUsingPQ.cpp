//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include<iostream>
using namespace std;
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,S});
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int d = it.first;
        for(auto it2 : adj[node]){
            
            int adjNode = it2[0];
            int edgeWt = it2[1];
            
            if(d + edgeWt < dist[adjNode]){
                dist[adjNode] = d + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    
    for(int i = 0; i<V; i++){
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
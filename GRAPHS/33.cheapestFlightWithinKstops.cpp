//https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops
#include<iostream>
using namespace std;
int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
    // Code here
    //first lets form an adj list 
    vector<pair<int,int>> adj[n];
    for(auto row : flights){
        adj[row[0]].push_back({row[1], row[2]});
    }
    queue<pair<int,pair<int,int>>> q; // k, [node, dist]
    q.push({0, {src, 0}});
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int node = it.second.first;
        int dis = it.second.second;
        int currentK = it.first;
        
        //visit all adj nodes
        for(auto x : adj[node]){
            int adjNode = x.first;
            int edgeW = x.second;
            if(currentK <= K && dis + edgeW < distance[adjNode]){
                distance[adjNode] = dis + edgeW;
                q.push({currentK + 1, {adjNode, dis+edgeW}});
            }
        }
    }
    
    if(distance[dst] != INT_MAX)    return distance[dst];
    else    return -1;
}
int main()
{
    return 0;
}
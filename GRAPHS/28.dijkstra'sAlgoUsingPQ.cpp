//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include<iostream>
using namespace std;
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    //declare a min heap that will store {dist, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    //declare the distance array and assign inf to each value 
    vector<int> dist(V, INT_MAX);
    
    //distance from s to s is 0
    dist[S] = 0;
    
    //push the source node into q
    pq.push({0,S});
    
    while(!pq.empty()){
        int d = pq.top().first;
        int n = pq.top().second;
        pq.pop();
        for(auto it : adj[n]){
            if(d+it[1] < dist[it[0]]){
                pq.push({d+it[1], it[0]});
                dist[it[0]] = d+it[1];
            }
        }
    }
    return dist;
}
int main()
{
    return 0;
}
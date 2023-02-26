//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
#include<iostream>
using namespace std;
//set based inmplementation 
vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
{
    //intialize the set
    set<pair<int,int>> st;
    //put the source node into the set
    st.insert({0,s});
    //initialize the distance matrix 
    vector<int> dist(V, INT_MAX);
    //mark the distance from source to source as 0
    dist[s] = 0;
    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase({dis, node});
        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgeW = it[1];
            if(dis + edgeW < dist[adjNode]){
                if(dist[adjNode] != INT_MAX){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
int main()
{
    return 0;
}
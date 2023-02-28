//https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-from-the-source-bellman-ford-algorithm
#include<iostream>
using namespace std;
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // Code here
    vector<int> distance(V,1e8);
    distance[S] = 0;
    
    //now relax all the edges V-1 times 
    for(int i = 0; i<V-1; i++){
        
        //relax all the edges 1 by 1
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
            }
        }
    }
    //now checking for negative cycle 
    //performing relaxation for the nth time 
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(distance[u] + wt < distance[v]){
            //if this is getting true... it means there is a negative cycle 
            return {-1};
        }
    }
    return distance;
}
int main()
{
    return 0;
}
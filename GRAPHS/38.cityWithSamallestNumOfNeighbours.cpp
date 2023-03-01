#include<iostream>
using namespace std;
//solved using floyd warshall algorithm 
//we can also solve it using dijkstra's algo as there are no negative cycle present 
int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
    
    //first lets form the adj matrix 
    vector<vector<int>> adj(n, vector<int>(n, -1));
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u][v] = wt;
        adj[v][u] = wt;
    }
    
    //now find the shortest path form every city to every another city 
    //using floyd warshall algo - a multisource shortest path algo
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j){
                adj[i][j] = 0;
            }
            else if(adj[i][j] == -1){
                //means there is no direct edge
                adj[i][j] = 1e9;
            }
        }
    }
    
    //now we will go to every node from every other node via every node 
    for(int via = 0; via<n; via++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(via == i || via == j){
                    //no changes required
                    continue;
                }
                else{
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }
    }
    
    //now we have the shortes distance from every node to every other node 
    //now for every city/node, find the number of reachable cities with distance <= T
    vector<int> temp;
    for(int i = 0; i<n; i++){
        int cnt = 0;
        for(int j = 0; j<n; j++){
            //if reachable with dis<=T, put 1 else put 0 in that cell 
            if(i!=j && adj[i][j] <= distanceThreshold){
                // adj[i][j] = 1;
                cnt++;
            }
        }
        temp.push_back(cnt);
    }
    
    //now the maximum value at temp vector is our ans
    int ansCity;
    int minCitiesReached = INT_MAX;
    for(int i = temp.size()-1; i>=0; i--){
        if(temp[i] < minCitiesReached){
            minCitiesReached = temp[i];
            ansCity = i;
        }
    }
    return ansCity;
}
int main()
{
    return 0;
}
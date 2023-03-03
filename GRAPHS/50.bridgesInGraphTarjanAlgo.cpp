//https://leetcode.com/problems/critical-connections-in-a-network/description/
#include<iostream>
using namespace std;
int timer = 1;
void dfs(int node, int parent, vector<int> &visArr, vector<int> adj[], 
        int timeIn[], int low[], vector<vector<int>> &bridges){
    
    visArr[node] = 1;
    timeIn[node] = low[node] = timer;
    timer++;
    //visit all the unvisited neighbours
    for(auto it : adj[node]){
        if(it == parent)    continue;
        if(!visArr[it]){
            dfs(it, node, visArr, adj, timeIn, low, bridges);
            //once the dfs call is finished 
            //update low
            low[node] = min(low[node], low[it]);
            //now check for edge between node and it 
            if(low[it] > timeIn[node]){
                bridges.push_back({it, node});
            }
        }
        else{
            //if some node is already visited .. 
            //so this edge cant be a bridge .. 
            //but just update the lowe time 
            low[node] = min(low[node], low[it]);
        }
    }
}
//we need to find the number of bridges - tarzan's algorithm 
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    //first lets form the adj list 
    vector<int> adj[n];
    for(auto it : connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> visArr(n, 0);
    int timeIn[n];
    int low[n];
    vector<vector<int>> bridges;
    dfs(0, -1, visArr, adj, timeIn, low, bridges);
    return bridges;
}
int main()
{
    return 0;
}
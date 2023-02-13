#include<iostream>
using namespace std;
bool dfs(int node, vector<int> adj[], vector<int> &visArr, int parent){
    
    visArr[node] = 1;
    
    for(auto x : adj[node]){
        if(!visArr[x]){
            if(dfs(x,adj,visArr, node)) return true;
        }
        else if(parent != x){
            return true;
        }
    }
    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<int> visArr(V,0);
    for(int i = 0; i<V; i++){
        if(!visArr[i])   {
            if(dfs(i,adj,visArr, -1)){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    return 0;
}
#include<iostream>
using namespace std;
bool bfs(int start, vector<int> &visArr, vector<int> adj[]){
    queue<pair<int,int>> q;
    q.push({start,-1});
    visArr[start] = 1;
    
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(int neighbour : adj[node]){
            if(!visArr[neighbour]){
                visArr[neighbour] = 1;
                q.push({neighbour,node});
            }
            else if(neighbour != parent){
                return true;
            }
        }
    }
    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<int> visArr(V,0);
    
    for(int i = 0; i<visArr.size(); i++){
        if(!visArr[i]){
            if(bfs(i,visArr,adj)){
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
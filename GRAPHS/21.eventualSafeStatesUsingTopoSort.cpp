#include<iostream>
using namespace std;
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    // apply topo sort
    //reverse all the edges of the graph 
    vector<int> reversedGraph[V];
    for(int i = 0; i<V; i++){
        for(int x : adj[i]){
            reversedGraph[x].push_back(i);
        }
    }
    //now calculate the indegree array 
    vector<int> indegree(V, 0);
    for(int i = 0; i<V; i++){
        for(int x : reversedGraph[i]){
            indegree[x]++;
        }
    }
    
    //now once we have the indegree 
    //push all the nodes with indegree = 0 into the queue 
    queue<int> q;
    for(int i = 0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : reversedGraph[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    return 0;
}
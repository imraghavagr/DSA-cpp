//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include<iostream>
using namespace std;
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    //topo sort only works for directed acyclic graphs.. so if there will be a cycle .. topo sort
    //would not be able to finish.
    
    vector<int> indegree(V, 0);
    for(int i = 0; i<V; i++){
        for(int x : adj[i]){
            indegree[x] += 1;
        }
    }
    //push all the nodes with indegree 0 into the queue 
    int cnt = 0;
    queue<int> q;
    for(int i = 0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(int x : adj[node]){
            indegree[x] -= 1;
            if(indegree[x] == 0)    q.push(x);
        }
    }
    
    return !(cnt == V);
}
int main()
{
    return 0;
}
//Given an adjacency list representation of a graph, return its bfs traversal
//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//For 1-index based graph
// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int n, vector<int> adj[], int startingNode) {
    // Code here
    vector<int> ans; 
    
    //queue for bfs
    queue<int> q;
    //visited array of size n because the graph is 0 based
    int visArr[n+1] = {0};
    
    //push the starting node into the q
    q.push(startingNode);
    //mark the starting node as visited
    visArr[startingNode] = 1;
    while(!q.empty()){
        int node = q.front();
        //push all unvisited neighbours of node into the q and mark them visited 
        for(int x : adj[node]){
            if(!visArr[x]){
                q.push(x);
                visArr[x] = 1;
            }
        }
        ans.push_back(node);
        q.pop();
    }
    return ans;
}

int main()
{   
    int n,m;
    cin>>n>>m;
    //array of vectors to store the graph
    vector<int> adjList[n+1];
    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        //undirected graph
    }
    for(int i = 0; i<=n; i++){
        cout<<i<<" -> ";
        for(int x : adjList[i]){
            cout<<x<<", ";
        }
        cout<<endl;
    }
    int startingNode = 2;
    vector<int> ans = bfsOfGraph(n, adjList, startingNode);
    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}

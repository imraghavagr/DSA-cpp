//Given an adjacency list representation of a graph, return its dfs traversal
//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include<iostream>
#include<vector>
using namespace std;

//For 1-index based graph
// Function to return Depth First Traversal of given graph.
void dfs(int node, vector<int> &visArr, vector<int> adjList[], vector<int> &ans){
    //mark the current node as visited 
    visArr[node] = 1;

    //this node is traversed also, so push it into the answer
    ans.push_back(node);

    //now traverse through all the neighbours of the current node
    for(int x : adjList[node]){
        if(!visArr[x]){
            dfs(x,visArr,adjList,ans);
        }
    }
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
    vector<int> visArr(n,0);
    int startingNode = 0;
    vector<int> ans;
    dfs(startingNode,visArr,adjList,ans);
    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}

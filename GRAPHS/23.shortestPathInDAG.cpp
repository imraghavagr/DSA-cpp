//https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph
#include<iostream>
using namespace std;
void dfs(int node, vector<pair<int,int>> adj[], stack<int> &stk, vector<int> &visArr){
    visArr[node] = 1;
    for(auto x : adj[node]){
        if(!visArr[x.first]){
            dfs(x.first, adj, stk, visArr);
        }
    }
    stk.push(node);
}
void topologicalSort(vector<pair<int,int>> adj[], int N, stack<int> &stk){
    //just apply normal dfs, and the node into the stack for which function call gets over
    vector<int> visArr(N, 0);
    for(int i = 0; i<N; i++){
        if(!visArr[i]){
            dfs(i, adj, stk, visArr);
        }
    }
}
bool relaxEdges(int source, vector<int> &dist, vector<pair<int,int>> adj[], stack<int> &stk){
    dist[source] = 0;
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();
        //for all adjacent nodes 
        if(dist[node] != INT_MAX){
            //we can only go to the adjacent node, if the dit of current node is updated atleast once
            for(auto x : adj[node]){
                int adjNode = x.first;
                int currDis = x.second;
                if(currDis + dist[node] < dist[adjNode]){
                    dist[adjNode] = currDis + dist[node];
                }
            }   
        }
    }
}
vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    // code here
    //first lets create adj list 
    vector<pair<int,int>> adj[N];
    for(int i = 0; i<M; i++){
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    
    //now apply topo sort 
    stack<int> topoSort;
    topologicalSort(adj, N, topoSort);
    
    //now once we have our stack ready - relax the edges
    vector<int> dist(N, INT_MAX);
    //start from source node - i.e. 0
    relaxEdges(0, dist, adj, topoSort);
    
    for(int i = 0; i<dist.size(); i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    return dist;
}

int main()
{   

    return 0;
}
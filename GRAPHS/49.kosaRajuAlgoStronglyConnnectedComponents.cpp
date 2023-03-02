//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo
#include<iostream>
using namespace std;
void dfs(int node, vector<int> &visArr, vector<vector<int>> &adj, stack<int> &stk){
    //mark the current node as visited 
    visArr[node] = 1;
    //traverse all unvisited adjacent nodes 
    for(auto it : adj[node]){
        if(!visArr[it]){
            dfs(it, visArr, adj, stk);
        }
    }
    stk.push(node);
}
//Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>>& adj)
{
    /*
    step 1 : sort the nodes w.r.t to finishing time 
    step 2 : reverse the edges 
    step 3 : perform dfs 
    */
    vector<int> visArr(V, 0);
    stack<int> stk;
    for(int i = 0; i<V; i++){
        if(!visArr[i]){
            dfs(i, visArr, adj, stk);
        }
    }
    //the element at the top of thes stack will be the node whose dfs is last to finish 
    //reverse the edges 
    vector<vector<int>> reverseGraph(V);
    for(int i = 0; i<V; i++){
        for(auto it : adj[i]){
            //write now we have edge from  i to it .. now make it from it to i 
            reverseGraph[it].push_back(i);
        }
    }
    //again mark all elements of visited array as unvisited 
    for(int i = 0; i<V; i++)    visArr[i] = 0;
    //step 3 - do a dfs 
    int cnt = 0;
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();
        if(!visArr[node]){
            cnt++;
            //there is no need of this stack now 
            dfs(node, visArr, reverseGraph, stk);
        }
        
    }
    return cnt;
}
int main()
{
    return 0;
}
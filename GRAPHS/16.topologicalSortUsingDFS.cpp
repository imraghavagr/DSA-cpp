//https://practice.geeksforgeeks.org/problems/topological-sort/1
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs(int node,vector<int> &visArr, vector<int> adj[], stack<int>&stk){
    //mark the current node as visited
    visArr[node] = 1;
    
    for(int n : adj[node]){
        if(!visArr[n]){
            dfs(n,visArr,adj,stk);
        }
    }
    stk.push(node);
}
//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> ans;
    vector<int> visArr(V,0);
    stack<int> stk;
    
    for(int i = 0; i<V; i++){
        if(!visArr[i]){
            dfs(i,visArr,adj,stk);
        }
    }
    
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}
int main()
{
    return 0;
}
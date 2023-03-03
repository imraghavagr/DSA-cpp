//https://practice.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point
#include<iostream>
using namespace std;
int timer = 0;
void dfs(int node, int parent, vector<int>&visArr, int tin[], int low[],
vector<int> &mark, vector<int> adj[]){
    visArr[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;
    for(auto it : adj[node]){
        if(it == parent) continue;
        if(!visArr[it]){
            dfs(it, node, visArr, tin, low, mark, adj);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tin[node] && parent != -1){
                mark[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }
    if(child > 1 && parent == -1){
        mark[node] = 1;
    }
    
}
vector<int> articulationPoints(int V, vector<int>adj[]) {
    // Code here
    vector<int> visArr(V, 0);
    int timeIn[V];
    int low[V];
    //to mark the articulation points 
    vector<int> mark(V, 0);
    for(int i = 0; i<V; i++){
        if(!visArr[i]){
            dfs(i, -1, visArr, timeIn, low, mark, adj);
        }
    }
    vector<int> ans;
    for(int i = 0; i<V; i++){
        if(mark[i] == 1){
            ans.push_back(i);
        }
    }
    if(ans.size() == 0) return {-1};
    return ans;
}
int main()
{
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, vector<int>&visArr, vector<int>&pathVis, vector<int>&check, vector<vector<int>>&graph){
    //mark the current node as visited and path visited
    visArr[node] = 1;
    pathVis[node] = 1;
    
    //check for all unvisited neighbours
    for(int n : graph[node]){
        if(!visArr[n]){
            if(dfs(n,visArr,pathVis,check,graph)){
                //if this returned true, means there is a cycle
                check[node] = 0;
                return true;
            }
        }
        //if the current node is already visited and also path visited
        else if(pathVis[n]){
            check[node] = 0;
            //cycle present 
            return true;
        }
    }
    
    check[node] = 1;
    pathVis[node]= 0;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int V  = graph.size();
    vector<int> visArr(V,0);
    vector<int> pathVis(V,0);
    vector<int> check(V,0);
    vector<int> ans;
    
    for(int i = 0; i<V; i++){
        if(!visArr[i]){
            dfs(i,visArr,pathVis,check,graph);
        }
    }
    
    for(int i = 0; i<V; i++){
        if(check[i]){
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    return 0;
}
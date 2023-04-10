//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
#include<iostream>
using namespace std;
bool dfs(int i, vector<int> &visArr, vector<int> &pathVisArr, vector<int> adj[]){
    visArr[i] = 1;
    pathVisArr[i] = 1;
    
    for(int x : adj[i]){
        if(!visArr[x]){
            if(dfs(x,visArr,pathVisArr,adj))return true;
        }
        else if(pathVisArr[x]){
            return true;
        }
    }
    pathVisArr[i] = 0;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visArr(V,0);
    vector<int> pathVisArr(V,0);
    for(int i = 0; i<visArr.size(); i++){
        if(!visArr[i] && dfs(i, visArr,pathVisArr,adj)){
            return true;
        }
    }
    return false;
}
//can also solve by using only 1 visArr, put 1 for visited and 2 for path visitted in the same array.
int main()
{
    return 0;
}
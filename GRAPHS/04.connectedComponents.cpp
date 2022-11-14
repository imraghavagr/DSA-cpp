//https://practice.geeksforgeeks.org/problems/number-of-provinces/1
//No. of provinces
#include<iostream>
using namespace std;

void dfs(int node, vector<int> &visArr, vector<vector<int>> &adj, int m){
    //mark the current node as visited 
    visArr[node] = 1;
    
    //now traverse all the unvisited neighbours of curr node 
    //all the neighbours or node are present in the nodeth row 
    for(int j = 0; j<m; j++){
        if(node != j && !visArr[j] && adj[node][j] == 1){
            dfs(j,visArr,adj,m);
        }
    }
}
void bfs(int node, vector<int> &visArr, vector<vector<int>> &adj, int m){
    queue<int> q;
    q.push(node);
    visArr[node] = 1;
    
    //now push all the unvisited neighbours of node into the queue and mark them visited while the q is not empty
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        //now iterate through the frTH row
        for(int j = 0; j<m; j++){
            if(fr != j && !visArr[j] && adj[fr][j] == 1){
                q.push(j);
                visArr[j] = 1;
            }
        }
    }
}
int numProvinces(vector<vector<int>> adj, int V) {
    // code here
    int m = adj[0].size();
    vector<int> visArr(V,0);
    int ans = 0;
    for(int i = 0; i<visArr.size(); i++){
        if(!visArr[i]){
            ans++;
            // dfs(i,visArr,adj,m);
            bfs(i,visArr,adj,m);
        }
    }
    return ans;
}
int main()
{
    return 0;
}
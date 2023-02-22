//https://practice.geeksforgeeks.org/problems/topological-sort/1
#include<iostream>
using namespace std;
//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    //we will need a indegree array 
    vector<int> indegree(V,0);
    for(int i = 0; i<V; i++){
        for(int x : adj[i]){
            indegree[x] += 1;
        }
    }
    
    //now apply bfs 
    queue<int> q;
    vector<int> ans;
    //firstly add all the nodes with indegree = 0 into the queue
    for(int i = 0; i<indegree.size(); i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    //there will be atleast one node in our queue, i.e. atleast one node will have indegree = 0 
    //because we are working with DAGs
    
    while(!q.empty()){
        int i = q.front();
        ans.push_back(i);
        q.pop();
        for(int x : adj[i]){
            indegree[x]-=1;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
        
    }
    return ans;
}
int main()
{
    return 0;
}
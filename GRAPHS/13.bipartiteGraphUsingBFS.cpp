//https://practice.geeksforgeeks.org/problems/bipartite-graph/1
#include<iostream>
using namespace std;

bool isBipartiteComponent(int V, vector<int>adj[], queue<int>&q, vector<int>&color, int start){
    q.push(start);
    //color the starting node with any color, lets say 0
    color[start] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        //iterate through all the neighbours
        for(int n : adj[node]){
            //if this neighbour is not colored, color it with the oposite color
            if(color[n] == -1){
                color[n] = !(color[node]);
                //push it into the queue
                q.push(n);
            }
            //return false if the adj node is already colored with the same color form some other branch
            else if(color[n] == color[node]){
                return false;
            }
        }
    }
    //exit from the loop, means we were able to color all the nodes in this component;
    return true;
}
bool isBipartite(int V, vector<int>adj[]){
    //bfs traversal technique
    //-1 means the graph is not colored 
    vector<int> color(V,-1);
    queue<int> q;
    
    for(int i = 0; i<V; i++){
        if(color[i] == -1){
            //check if this componenet is bipartite or not
            if(!isBipartiteComponent(V,adj,q,color,i)){
                return false;
            }
        
        }
    }
    //entire graph is bipartite if all the components are bipartite
    return true;
}
int main()
{
    return 0;
}
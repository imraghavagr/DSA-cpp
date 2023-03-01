#include<iostream>
using namespace std;
//if the edges of min spanning tree are also asked 
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
    //we just need to return the sum of the spanning tree 
    int sum = 0;
    vector<pair<int,int>> mst;
    
    vector<int> visArr(V, 0);
    
    pq.push({0, {0, -1}});
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int edgeW = it.first;
        int node = it.second.first;
        int parent = it.second.second;
        
        //now if the current node is not visited 
        if(!visArr[node]){
            //means put the edge parent->node into the mst and add the edgeW into the sum 
            if(parent != -1){
                mst.push_back({parent, node});    
                sum += edgeW;
            }
            //also mark it as visited 
            visArr[node] = 1;
            //now once we are standing at node, explore all the unvisited neighbours of node 
            for(auto it : adj[node]){
                int adjNode = it[0];
                int adjEdge = it[1];
                if(!visArr[adjNode]){
                    pq.push({adjEdge, {adjNode, node}});
                }
            }
        }
    }
    return sum;
}
//if the edges are not asked, only sum is asked, then no need to store the parent into the priority queue
int spanningTree2(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    //we just need to return the sum of the spanning tree 
    int sum = 0;
    
    vector<int> visArr(V, 0);
    
    pq.push({0,0});
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int edgeW = it.first;
        int node = it.second;
        
        //now if the current node is not visited 
        if(!visArr[node]){
            //add the edgeW into the sum 
            sum += edgeW;
            //also mark it as visited 
            visArr[node] = 1;
            //now once we are standing at node, explore all the unvisited neighbours of node 
            for(auto it : adj[node]){
                int adjNode = it[0];
                int adjEdge = it[1];
                if(!visArr[adjNode]){
                    pq.push({adjEdge, adjNode});
                }
            }
        }
    }
    return sum;
}
int main()
{
    return 0;
}
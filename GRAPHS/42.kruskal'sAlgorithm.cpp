//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
#include<iostream>
using namespace std;
class DisjointSet{
    vector<int> size;
    vector<int> parent;
public:
    //ctor
    DisjointSet(int n){
        //will make it for both 0 based and 1 based indexing graphs
        size.resize(n+1, 1); //intitially component size of each node = 1
        parent.resize(n+1);
        //also initially every node is the parent of itself
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }
    //find ultimate parent
    int findUltimateParent(int node){
        if(parent[node] == node)
            //if the parent of this node is that node itself, then this node is the ultimate parent
            return node;
        
        // return findUltimateParent(parent[node]); 
        //but the above line will again and again take logarithmic time 
        //therefore we need to add path compression also - 
        //that is we will connect the node to its ultimate parent directyl
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionBySize(int u, int v){
        //now we have to nodes with an edge between them, we need to connect them

        //first find ultimate parent of both the nodes 
        int ultParentOfU = findUltimateParent(u);
        int ultParentOfV = findUltimateParent(v);
        
        // if both the ultimate parents are same, it means they belong to the same component..
        //so we do not need to do anything
        if(ultParentOfU == ultParentOfV)    return;

        //now connect according to sizes 
        if(size[ultParentOfU] < size[ultParentOfV]){
            //connect u to v - update parent of u
            parent[ultParentOfU] = ultParentOfV;
            size[ultParentOfV] += size[ultParentOfU];
        }
        else {
            //for the remaining two cases
            parent[ultParentOfV] = ultParentOfU;
            size[ultParentOfU] += size[ultParentOfV];
        }
    }
};
//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    //first lets convert the adjList into a vector of edges 
    //O(V+E)
    vector<pair<int,pair<int,int>>> edges;
    for(int i = 0; i<V; i++){
        for(auto it : adj[i]){
            int adjNode = it[0];
            int edgeW = it[1];
            edges.push_back({edgeW, {i, adjNode}});
        }
    }
    
    //now we need to sort the edges w.r.t to edgeWeights
    
    //O(ElogE)
    sort(edges.begin(), edges.end());
    
    int ans = 0;
    
    //declare a disjoint set with V number of nodes 
    DisjointSet ds(V);
    //now connect all the nodes using union by size 
    //O(E)
    for(auto it : edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        //O(4 * alpha) ~ O(1)
        if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
            //if the ultimate parent of two nodes is not same, then ..
            //this means they are in the different components
            ds.unionBySize(u,v);
            ans += wt;
        }
    }
    return ans;
}
int main()
{
    return 0;
}
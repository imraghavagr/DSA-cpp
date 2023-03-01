//https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph
#include<iostream>
using namespace std;
class DisjointSet{
public:
    vector<int> size;
    vector<int> parent;
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
int Solve(int n, vector<vector<int>>& edge) {
    // code here
    DisjointSet ds(n);
    //variable to maintain cnt of extra edges        
    int extraEdges = 0;
    for(auto it : edge){
        int u = it[0];
        int v = it[1];
        
        //an edge will be extra if they will have same ultimate parent 
        if(ds.findUltimateParent(u) == ds.findUltimateParent(v))
            extraEdges++;
        else
            ds.unionBySize(u,v);
    }
    //now find the number of connected components
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(ds.parent[i] == i)  cnt++;
    }
    if(extraEdges >= cnt-1){
        return cnt-1;
    }
    else{
        return -1;   
    }
}
int main()
{
    return 0;
}
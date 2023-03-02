//https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-stone-removal
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

int maxRemove(vector<vector<int>>& stones, int n) {
    // Code here
    //treat entire row as 1 node and entire 1 col as 1 node 
    int numOfRows = -1;
    int numOfCols = -1;
    
    for(auto it : stones){
        numOfRows = max(numOfRows, it[0]);
        numOfCols = max(numOfCols, it[1]);
    }
    
    int totalNodes = numOfRows + numOfCols + 1;
    
    DisjointSet ds(totalNodes);
    
    unordered_set<int> nodesInvolved;
    //now connect all the stones/nodes one by one 
    for(auto it : stones){
        int i  = it[0];
        int j = it[1];
        int node1 = i;
        int node2 = numOfRows + j + 1;
        
        //connect node1 and node2 if they are already not connected 
        if(ds.findUltimateParent(node1) == ds.findUltimateParent(node2)) continue;
        
        ds.unionBySize(node1, node2);
        //we only need the stones in ds which are involved in having a stone.
        nodesInvolved.insert(node1);
        nodesInvolved.insert(node2);
    }
    //now find the number of connected components
    
    int numOfComponents = 0;
    for(auto it : nodesInvolved){
        if(ds.findUltimateParent(it) == it)
            numOfComponents++;
    }
    //the number of stones that can be removed = 
    //total number of stones - number of components 
    return n - numOfComponents;
}
int main()
{
    return 0;
}
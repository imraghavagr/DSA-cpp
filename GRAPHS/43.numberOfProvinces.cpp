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
//this time we will solve it using disjoint set data structure 
int numProvinces(vector<vector<int>> adj, int V) {
    // code here
    DisjointSet ds(V);
    
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            if(adj[i][j] == 1){
                //means there is an edge between i and j 
                ds.unionBySize(i,j);
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i<V; i++){
        if(ds.findUltimateParent(i) == i){
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    return 0;
}
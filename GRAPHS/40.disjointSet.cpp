#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    vector<int> rank;
    vector<int> parent;
public:
    //ctor
    DisjointSet(int n){
        //will make it for both 0 based and 1 based indexing graphs
        rank.resize(n+1, 0);
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
        
        // return findUltimateParent(parent[node]); but this line will again and again take logarithmic time 
        //we need to add path compression also - that is we will connect the node to its ultimate parent directyl
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByRank(int u, int v){
        //now we have to nodes with an edge between them, we need to connect them

        //first find ultimate parent of both the nodes 
        int ultParentOfU = findUltimateParent(u);
        int ultParentOfV = findUltimateParent(v);
        
        // if both the ultimate parents are same, it means they belong to the same componend.. so we do not need to do anything
        if(ultParentOfU == ultParentOfV)    return;

        //now connect according to ranks 
        if(rank[ultParentOfU] < rank[ultParentOfV]){
            //connect u to v - update parent of u
            parent[ultParentOfU] = ultParentOfV;
        }
        else if(rank[ultParentOfV] < rank[ultParentOfU]){
            parent[ultParentOfV] = ultParentOfU;
        }
        else{
            //if both the ranks are same 
            //connect any one to anyone 
            parent[ultParentOfV] = ultParentOfU;
            //since we connected v to u .. rank of u will increase by 1
            rank[ultParentOfU]+=1;
        }
    }
};
int main()
{   
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    //lets check if 3 and 7 belong to same component or not 
    //check if they have same boss/ulimate parent of not 
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    ds.unionByRank(3,7);

    //now again check if 3 and 7 are in the same componet after adding an edge between 3 and 7
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
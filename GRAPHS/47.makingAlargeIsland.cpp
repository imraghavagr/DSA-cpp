//https://practice.geeksforgeeks.org/problems/maximum-connected-group/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-connected-group
#include<iostream>
using namespace std;

class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }
    int findUltimateParent(int node){
        if(parent[node] == node)    return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        if(pu == pv)    return;

        if(size[pu] < size[pv]){
            //connect u to v 
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }
        else{
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }
    }
};

bool isValid(int i, int j, int n, int m){
    return i>=0 && i<n && j>=0 && j<m;
}
int MaxConnection(vector<vector<int>>& grid) {
    // code here
    int n = grid.size();
    int m = grid[0].size();
    DisjointSet ds(n*m);
    int delR[] = {0, -1, 0, 1};
    int delC[] = {-1, 0, 1, 0};
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 1){
                //try to connect it with all the other adjacent 1s 
                for(int k = 0; k<4; k++){
                    int adjR = i + delR[k];
                    int adjC = j + delC[k];
                    if(isValid(adjR, adjC, n, m) &&
                        grid[adjR][adjC] == 1){
                        int u = i*m + j;
                        int v = adjR*m + adjC;
                        //connect if they are already not connected
                        if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                            ds.unionBySize(u, v);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    //now we will iterate though all the 0's 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 1) continue;
            //below code will only be executed for 0's 
            unordered_set<int> st;
            ///check all 4 neighbours 
            for(int k = 0; k<4; k++){
                int adjR = i + delR[k];
                int adjC = j + delC[k];
                if(isValid(adjR, adjC, n, m) && grid[adjR][adjC] == 1){
                    int node = adjR*m + adjC;
                    //store the ultimate parent of this node into a set
                    st.insert(ds.findUltimateParent(node));
                    
                }
            }
            //now we have all the adjacent unique components to this 0 inside the set 
            int totalSize = 0;
            for(auto it : st){
                totalSize += ds.size[it];
            }
            //+1 for current 0
            ans = max(ans, totalSize+1);
        }
    }
    //there is still a case remaining , when an existing component, i.e. without changing 0 
    //has the max size 
    for(int node = 0; node<(m*n); node++){
        ans = max(ans, ds.size[ds.findUltimateParent(node)]);
    }
    return ans;
}
int main()
{
    return 0;
}
//https://leetcode.com/problems/number-of-islands-ii/description/
#include<iostream>
using namespace std;
class DisjointSet{
    vector<int> size, parent;
public:
    DisjointSet(int n){
        //we have 0 based indexing 
        size.resize(n,1);
        parent.resize(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }
    int findUltimateParent(int n){
        if(parent[n] == n)  return n;

        return parent[n] = findUltimateParent(parent[n]);
    }
    void unionBySize(int u, int v){
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);
        if(ultimateParentU == ultimateParentV){
            return;
        }
        if(size[ultimateParentU] < size[ultimateParentV]){
            //connect u to v 
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += ultimateParentU;
        }
        else{
            //connect v to u 
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += ultimateParentV;
        }
    }
};
vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    //total cells of graph - m*n
    DisjointSet ds(m*n);
    vector<int> ans;
    vector<vector<int>> visArr(m, vector<int>(n,0));
    //iterate through all the postions 
    int delR[] = {0,-1,0,1};
    int delC[] = {-1,0,1,0};
    int cnt = 0;
    for(auto it : positions){
        int i = it[0];
        int j = it[1];
        //mark the current cell as visited if it is not visited 
        if(!visArr[i][j]){
            cnt++;
            visArr[i][j] = 1;
            //go to all four directions
            for(int k = 0; k<4; k++){
                int row = i + delR[k];
                int col = j + delC[k];
                if(row>=0 && col>=0 && row<m && col<n
                    && visArr[row][col] == 1){
                    
                    //connect ro, col to i, j if they are not already connected 
                    int u = (i*n) + j;
                    int v = (row*n) + col;
                    if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                        cnt--;
                        ds.unionBySize(u,v);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}
int main()
{
    return 0;
}
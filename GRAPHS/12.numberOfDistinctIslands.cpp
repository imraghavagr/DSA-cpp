#include<iostream>
#include<vector>
#include<set>
using namespace std;

void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &visArr, set<vector<pair<int,int>>> &st, int m, int n){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    visArr[i][j] = 1;
    //this i,j is the base of the island 
    //add this into the set
    vector<pair<int,int>> v;
    int baseI = i;
    int baseJ = j;
    v.push_back({i-baseI,j-baseJ});
    //now traverse all the unvisited valid neighbours
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        //left and right
        for(int k = -1; k <= 1; k++){
            if(j+k>=0 && j+k<n && !visArr[i][j+k] && grid[i][j+k] == 1){
                q.push(make_pair(i,j+k));
                v.push_back({i-baseI,(j+k)-baseJ});
                visArr[i][j+k] = 1;
            }
        }
        //up and down
        for(int k = -1; k <= 1; k++){
            if(i+k>=0 && i+k<m && !visArr[i+k][j] && grid[i+k][j] == 1){
                q.push(make_pair(i+k,j));
                v.push_back({(i+k)-baseI, j-baseJ});
                visArr[i+k][j] = 1;
            }
        }
    }
    st.insert(v);
    
}
int countDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> visArr(m,vector<int>(n,0));
    
    set<vector<pair<int,int>>> st;
    //lets use the bfs traversal technique
    for(int i = 0; i<m; i++){
        for(int j =0; j<n; j++){
            if(!visArr[i][j] && grid[i][j] == 1){
                bfs(i,j,grid,visArr,st, m, n);
            }
        }
    }
    return st.size();
    // code here
}
int main()
{
    return 0;
}
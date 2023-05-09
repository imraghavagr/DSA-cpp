#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> delR = {-1, 0, 1, 0};
vector<int> delC = {0, 1, 0, -1};
bool isValid(int i, int j, int m, int n){
    if(i>=0 && i<m && j>=0 && j<n)  return true;
    else    return false;
}

//using bfs
void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visArr,
vector<pair<int,int>> &v, int m, int n, int baseI, int baseJ){

    queue<pair<int,int>> q;
    q.push({i,j});
    visArr[i][j] = 1;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        i = it.first;
        j = it.second;
        for(int k = 0; k<4; k++){
            int newR = i + delR[k];
            int newC = j + delC[k];
            if(isValid(newR, newC, m, n) && !visArr[newR][newC] && grid[newR][newC] == 1){
                visArr[newR][newC] = 1;
                v.push_back({newR-baseI, newC-baseJ});
                q.push({newR, newC});
            }
        }
    }

}
int numDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visArr(m, vector<int>(n, 0));
    set<vector<pair<int,int>>> st;
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            vector<pair<int,int>> v;
            if(!visArr[i][j] && grid[i][j] == 1){
                v.push_back({i-i,j-j});
                //we will also pass the baseI and baseJ as i and i
                bfs(i,j,grid,visArr,v, m, n, i, j);
                st.insert(v);
            }
        }
    }
    return st.size();
}

//using dfs
void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visArr,
vector<pair<int,int>> &v, int m, int n, int baseI, int baseJ){

    visArr[i][j] = 1;
    // v.push_back({i-baseI,j-baseJ});
    for(int k = 0; k<4; k++){
        int newR = i + delR[k];
        int newC = j + delC[k];
        if(isValid(newR, newC, m, n) && !visArr[newR][newC] && grid[newR][newC] == 1){
            v.push_back({newR-baseI, newC-baseJ});
            dfs(newR, newC, grid, visArr, v, m, n, baseI, baseJ);
        }
    }
}
int numDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visArr(m, vector<int>(n, 0));
    set<vector<pair<int,int>>> st;
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            vector<pair<int,int>> v;
            if(!visArr[i][j] && grid[i][j] == 1){
                v.push_back({i-i,j-j});
                //we will also pass the baseI and baseJ as i and i
                dfs(i,j,grid,visArr,v, m, n, i, j);
                st.insert(v);
            }
        }
    }
    return st.size();
}
int main()
{
    return 0;
}
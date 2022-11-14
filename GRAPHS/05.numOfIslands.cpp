//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

void dfs(int i, int j, vector<vector<int>> &visArr, vector<vector<char>>& grid, int m, int n){
    visArr[i][j] = 1;
    
    for(int p = -1; p<=1; p++){
        for(int q = -1; q<=1; q++){
            if(i+p>=0 && i+p<m && j+q>=0 && j+q<n && grid[i+p][j+q] == '1' && !visArr[i+p][j+q]){
                dfs(i+p,j+q, visArr, grid, m, n);
            }
        }
    }
}
// Function to find the number of islands.
int numIslands(vector<vector<char>>& grid) {
    // Code here
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visArr(m,vector<int>(n,0));
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j] == '1' && !visArr[i][j]){
                dfs(i,j,visArr,grid,m,n);
                ans++;
            }
        }
    }
    return ans;
    
}
#include<iostream>
#include<vector>
using namespace std;

int bfs(queue<pair<int,int>> &q, vector<vector<int>> &visArr, vector<vector<int>> &grid, int m, int n){
    int ans = 0;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        //traverse in all 4 valid directions from i,j
        
        //left and right
        for(int k = -1; k<=1; k++){
            if(j+k>=0 && j+k<n && !visArr[i][j+k] && grid[i][j+k] == 1){
                q.push(make_pair(i,j+k));
                visArr[i][j+k] = 1;
            }
        }
        //up and down
        for(int k = -1; k<=1; k++){
            if(i+k>=0 && i+k<m && !visArr[i+k][j] && grid[i+k][j] == 1){
                q.push(make_pair(i+k,j));
                visArr[i+k][j] = 1;
            }
        }
        
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(!visArr[i][j] && grid[i][j] == 1){
                ans++;
            }
        }
    }
    return ans;
}
int numberOfEnclaves(vector<vector<int>> &grid) {
    // Code here

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visArr(m,vector<int>(n,0));
    
    queue<pair<int,int>> q;
    //push all the boundary 1's into the queue
    
    //traverse first row and last row
    for(int j = 0; j<n; j++){
        //first row
        if(grid[0][j] == 1){
            q.push(make_pair(0,j));
            visArr[0][j] = 1;
        }
        //last row
        if(grid[m-1][j] == 1){
            q.push(make_pair(m-1,j));
            visArr[m-1][j] = 1;
        }
    }
    //traverse first col and last col
    for(int i = 0; i<m; i++){
        //first col
        if(grid[i][0] == 1){
            q.push(make_pair(i,0));
            visArr[i][0] = 1;
        }
        //last col
        if(grid[i][n-1] == 1){
            q.push(make_pair(i,n-1));
            visArr[i][n-1] = 1;
        }
    }
    
    return bfs(q,visArr,grid, m, n);
}
int main(){

    return 0;
}
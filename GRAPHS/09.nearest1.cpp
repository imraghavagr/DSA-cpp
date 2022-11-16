//https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>> &ans, vector<vector<int>> &grid, vector<vector<int>> &visArr,int m, int n){
    queue<pair<pair<int,int>,int>> q;
    //lets add all the initial ones in the queue and mark them visited
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j] == 1){
                q.push(make_pair(make_pair(i,j),0));
                visArr[i][j] = 1;
            }
        }
    }
    
    //now start traversing using bfs
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int d = q.front().second;
        
        q.pop();
        
        //now traverse in all 4 directions
        
        //for left and right 
        for(int k = -1; k<=1; k++){
            if(j+k>=0 && j+k<n && !visArr[i][j+k] && grid[i][j+k] == 0){
                ans[i][j+k] = d+1;
                //push this neighbour into the queue
                q.push(make_pair(make_pair(i,j+k),d+1));
                //also mark it visited
                visArr[i][j+k] = 1;
            }
        }
        //for up and down
        for(int k = -1; k<=1; k++){
            if(i+k>=0 && i+k<m && !visArr[i+k][j] && grid[i+k][j] == 0){
                ans[i+k][j] = d+1;
                //push this neighbour into the queue
                q.push(make_pair(make_pair(i+k,j),d+1));
                //also mark it visited
                visArr[i+k][j] = 1;
            }
        }
    }
                
}
//Function to find distance of nearest 1 in the grid for each cell.
vector<vector<int>>nearest(vector<vector<int>>grid)
{
    // Code here
    int m = grid.size();
    int n = grid[0].size();
    
    //visArr
    vector<vector<int>> visArr(m,vector<int>(n,0));
    
    //ans matrix
    vector<vector<int>> ans(m,vector<int>(n,0));
    
    solve(ans,grid,visArr,m,n);
    
    return ans;
}

int main()
{
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    queue <pair<pair<int,int>,int>> q;
    vector<vector<int>> visArr(n,vector<int>(m,0));
    int cntOfFreshOranges = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 2 ){
                //means there is an orange at this cell 
                //add this to queue
                q.push(make_pair(make_pair(i,j),0));
                //mark the visArray as 1 for this cell 
                visArr[i][j] = 1;
            }
            else if(grid[i][j] == 1){
                cntOfFreshOranges++;
            }
        }
    }
    
    int maxTime = 0;
    int cntOfConvertedOranges = 0;
    //bfs
    //q already contains the starting nodes, and visArr is also already marked. 
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int t = q.front().second;
        maxTime = max(maxTime, t);
        q.pop();
        //now traverse in all 4 directions from i,j th cell 
        for(int p = -1; p<=1; p++){
            if(i+p >= 0 && i+p <n && !visArr[i+p][j] && grid[i+p][j] == 1){
                q.push(make_pair(make_pair(i+p,j),t+1));
                //mark this node as visited 
                visArr[i+p][j] = 1;
                cntOfConvertedOranges++;
            }
        }
        for(int p = -1; p<=1; p++){
            if(j+p >= 0 && j+p <m && !visArr[i][j+p] && grid[i][j+p] == 1){
                q.push(make_pair(make_pair(i,j+p),t+1));
                //mark this node as visited 
                visArr[i][j+p] = 1;
                cntOfConvertedOranges++;
            }
        }
    }
    if(cntOfFreshOranges != cntOfConvertedOranges){
        return -1;
    }
    else{
        return maxTime;
    }
}

int main()
{
    return 0;
}
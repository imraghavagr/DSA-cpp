#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> visArr(m,vector<int>(n,0));
    
    queue<pair<int,int>> q;
    //push all the boundary zeros into the queue
    
    //traverse first row and last row 
    for(int j = 0; j<n; j++){
        //first row
        if(board[0][j] == 'O'){
            visArr[0][j] = 1;
            q.push(make_pair(0,j));
        }
        //last row
        if(board[m-1][j] == 'O'){
            visArr[m-1][j] = 1;
            q.push(make_pair(m-1,j));
        }
    }
    //traverse first col and last col
    for(int i = 0; i<m; i++){
        //first col
        if(board[i][0] == 'O'){
            visArr[i][0] = 1;
            q.push(make_pair(i,0));
        }
        //last col
        if(board[i][n-1] == 'O'){
            visArr[i][n-1] = 1;
            q.push(make_pair(i,n-1));
        }
    }
    
    //now applly bfs 
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        //traverse in all 4 valid directions from i,j
        
        //left and right
        for(int k = -1; k<=1; k++){
            if(j+k>=0 && j+k<n && !visArr[i][j+k] && board[i][j+k] == 'O'){
                q.push(make_pair(i,j+k));
                visArr[i][j+k] = 1;
            }
        }
        //up and down
        for(int k = -1; k<=1; k++){
            if(i+k>=0 && i+k<m && !visArr[i+k][j] && board[i+k][j] == 'O'){
                q.push(make_pair(i+k,j));
                visArr[i+k][j] = 1;
            }
        }            
    }
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(!visArr[i][j]){
                board[i][j] = 'X';
            }
        }
    }        
}

int main()
{
    return 0;
}
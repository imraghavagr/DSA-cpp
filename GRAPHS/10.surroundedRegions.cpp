#include<iostream>
#include<vector>
using namespace std;

vector<int> delR = {-1, 0, 1, 0};
vector<int> delC = {0, 1, 0, -1};
bool isValid(int i, int j, int m, int n){
    if(i>=0 && i<m && j>=0 && j<n)  return true;
    else    return false;
}
void bfs(vector<vector<char>> &board, vector<vector<int>> &visArr, queue<pair<int,int>> &q, int m, int n){
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int i = it.first;
        int j = it.second;
        //visit all unvisited neighbours
        for(int k = 0; k<4; k++){
            int newR = i + delR[k];
            int newC = j + delC[k];
            if(isValid(newR, newC, m, n) && !visArr[newR][newC] && board[newR][newC] == 'O'){
                q.push({newR, newC});
                visArr[newR][newC] = 1;
            }
        }
    }
}
void solve(vector<vector<char>>& board) {
    queue<pair<int,int>> q;
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> visArr(m, vector<int>(n, 0));
    //push all the boundary O into the queue
    for(int j = 0; j<n; j++){
        if(board[0][j] == 'O'){
            q.push({0,j});
            visArr[0][j] = 1;
        }
        if(board[m-1][j] == 'O'){
            q.push({m-1, j});
            visArr[m-1][j] = 1;
        }
    }
    for(int i = 1; i<m-1; i++){
        if(board[i][0] == 'O'){
            q.push({i,0});
            visArr[i][0] = 1;
        }
        if(board[i][n-1] == 'O'){
            q.push({i, n-1});
            visArr[i][n-1] = 1;
        }
    }
    bfs(board, visArr, q, m, n);
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
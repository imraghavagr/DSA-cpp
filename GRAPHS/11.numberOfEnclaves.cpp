#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> delR = {-1, 0, 1, 0};
vector<int> delC = {0, 1, 0, -1};
bool isValid(int i, int j, int m, int n){
    if(i>=0 && i<m && j>=0 && j<n)  return true;
    else    return false;
}
void dfs(int i, int j, vector<vector<int>> &visArr, vector<vector<int>> &board){
    int m = board.size();
    int n = board[0].size();
    visArr[i][j] = 1;
    for(int k = 0; k<4; k++){
        int newR = i + delR[k];
        int newC = j + delC[k];
        if(isValid(newR, newC, m, n) && !visArr[newR][newC] && board[newR][newC] == 1){
            dfs(newR, newC, visArr, board);
        }
    }
}
int numEnclaves(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> visArr(m, vector<int>(n, 0));
    //start traversal from all the boundary 1s and traverse all the connected 1's from that 1 
    // all the 1s that will be visited in this traversal can not be counted 
    for(int j = 0; j<n; j++){
        if(board[0][j] == 1){
            dfs(0,j,visArr, board);
        }
        if(board[m-1][j] == 1){
            dfs(m-1,j,visArr, board);
        }
    }
    for(int i = 1; i<m-1; i++){
        if(board[i][0] == 1){
            dfs(i,0,visArr, board);
        }
        if(board[i][n-1] == 1){
            dfs(i,n-1,visArr, board);
        }
    }
    int cnt = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == 1 && !visArr[i][j])   cnt++;
        }
    }
    return cnt;
}
int main(){

    return 0;
}
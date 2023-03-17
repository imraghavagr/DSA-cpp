#include<iostream>
using namespace std;
bool isSafe(vector<string> board, int row, int col, int n){
    //check if it is safe to place a queen in current row, col cell 
    int tempRow = row;
    int tempCol = col;

    //check for left upper side 
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q')  return false;
        row--;
        col--;
    }

    row = tempRow;
    col = tempCol;

    //check for adjacent lefts 
    while(col>=0){
        if(board[row][col] == 'Q')  return false;
        col--;
    }

    row = tempRow;
    col = tempCol;
    //check for left down side 
    while(row<n && col >= 0){
        if(board[row][col] == 'Q')  return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    //base case
    if(col == n){
        ans.push_back(board);
        return;
    }

    //try to place queens at each row of current col 
    for(int i = 0; i<n; i++){
        if(isSafe(board, i, col, n)){
            board[i][col] = 'Q';
            //once placed in this row, try to place in next col
            solve(col+1, board, ans, n);
            //while backtracking, remove the earlier placed queen 
            board[i][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    //we have created a board using a vector of strings 
    //each string has ". . . ." n dots and we have n such strings 
    //placed in the vector .. acting as a chessboard 
    for(int i = 0; i<n; i++){
        board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}
int main()
{
    return 0;
}
#include<iostream>
using namespace std;
bool isPossible(int row, int col, vector<int> &leftRow, vector<int> &upperLeftDiagonal, vector<int> &lowerLeftDiagonal, int n){
    //for left row 
    if(leftRow[row] == 1)   return false;
    if(upperLeftDiagonal[(n-1) + (col-row)] == 1)   return false;
    if(lowerLeftDiagonal[row+col] == 1) return false;

    return true;
}
void solve(int col, vector<string> &board, int n, vector<vector<string>> &ans,
vector<int> &leftRow, vector<int> &upperLeftDiagonal, vector<int> &lowerLeftDiagonal){

    //base case - if we have succefully placed queen at n-1th col then return 
    if(col == n){
        ans.push_back(board);
        return;
    }

    //now for each col, try placing queens at all rows 
    for(int row = 0; row<n; row++){
        //check if it is possible to place queen at current cell 
        if(isPossible(row, col, leftRow, upperLeftDiagonal, lowerLeftDiagonal, n)){
            //place the queen 
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperLeftDiagonal[(n-1) + (col-row)] = 1;
            lowerLeftDiagonal[row+col] = 1;
            solve(col+1, board, n, ans, leftRow, upperLeftDiagonal, lowerLeftDiagonal);
            board[row][col] = '.';
            leftRow[row] = 0;
            upperLeftDiagonal[(n-1) + (col-row)] = 0;
            lowerLeftDiagonal[row+col] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n);
    string s(n, '.');
    for(int i = 0; i<n; i++){
        board[i] = s;
    }
    vector<vector<string>> ans;
    //three separate hashing arrays to check is safe in all three directions 
    vector<int> leftRow(n, 0); 
    vector<int> upperLeftDiagonal(2*n-1, 0);
    vector<int> lowerLeftDiagonal(2*n-1, 0);
    //start placing queen at each row from 0th col 
    solve(0, board, n, ans, leftRow, upperLeftDiagonal, lowerLeftDiagonal);
    return ans;
}
int main()
{
    return 0;
}
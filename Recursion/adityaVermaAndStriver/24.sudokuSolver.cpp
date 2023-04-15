#include<iostream>
using namespace std;
bool isValid(int row, int col, char ch, vector<vector<char>> &board, int n){
    for(int index = 0; index < 9; index++){
        //for current row 
        if(board[row][index] == ch) return false;
        //for current col - rows will change 
        if(board[index][col] == ch) return false;
        //for current 3x3 subgrid 
        if(board[3*(row/3) + index/3][3*(col/3) + index%3] == ch) return false;
    }
    return true;
}
bool solve(vector<vector<char>> &board, int n){
    //find every empty cell and try to fill valid values in that cell 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            //find the empty cell 
            if(board[i][j] == '.'){
                //try to fill values from 1 to 9 
                for(char ch = '1'; ch<='9'; ch++){
                    //check if placing ch at i,j is safe or not 
                    if(isValid(i,j,ch,board,n)){
                        //place ch here
                        board[i][j] = ch;
                        if(solve(board, n)){
                            return true;
                        }
                        else{
                            board[i][j] = '.';
                        }
                        
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board, board.size());
}
int main()
{
    return 0;
}
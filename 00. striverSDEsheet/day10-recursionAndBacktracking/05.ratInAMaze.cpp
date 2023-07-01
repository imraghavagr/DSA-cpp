#include<iostream>
using namespace std;
void solve(int i, int j, vector<vector<int>> &maze, string &op,vector<vector<int>> &visArr,
vector<string> &ans, int n){
    if(i == n-1 && j == n-1){
        ans.push_back(op);
        return;
    }    
    //from current i, j we will try to move in 4 directcftions if possible 
    //D, L, R, U
    int delR[] = {1, 0, 0, -1};
    int delC[] = {0, -1, 1, 0};
    char directions[] = {'D', 'L','R', 'U'};
    for(int k = 0; k<4; k++){
        int row = i + delR[k];
        int col = j + delC[k];
        //now check if gng to row,col is possible or not 
        if(row>=0 && row<n && col>=0 && col<n && !visArr[row][col] && maze[row][col] == 1){
            op.push_back(directions[k]);
            visArr[row][col] = 1;
            solve(row, col, maze, op, visArr, ans, n);
            //while backtracking 
            op.pop_back();
            visArr[row][col] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &maze, int n) {
    // Your code goes here
    vector<string> ans;
    string op;
    vector<vector<int>> visArr(n, vector<int>(n, 0));
    visArr[0][0] = 1;

    // if(maze[0][0] == 1){
    //     solve(0,0, maze,op, visArr, ans, n);   
    // }
    if(maze[0][0] == 0){
        return ans;
    }
    solve(0,0, maze,op, visArr, ans, n);
    return ans;
}
int main()
{
    return 0;
}
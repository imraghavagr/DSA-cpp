#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
    
    //rotate 90 degree clockwise
    //1- transpose the matrix, 2- reverse all rows
    if(matrix.size()==1)return;

    for(int i = 1; i<matrix.size(); i++){
        for(int j = 0; j<i; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    //now take reverse of each row
    for(int row = 0; row<matrix.size(); row++){
        //reverse the ith row
        reverse(matrix[row].begin(),matrix[row].end());
    }
}
int main()
{   
    

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

//o(m+n) space and O(mn) time
void setZeroes1(vector<vector<int>>& matrix) {
    //firt we need to create two vectors - row and col to store if that ith row or jth col has any
    //0 in it
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m,-1);
    vector<int> col(n,-1);
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(matrix[i][j] == 0){
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(row[i]==0 || col[j] ==0){
                matrix[i][j] = 0;
            }
        }
    }
}

//O(1) space and O(mn) time
void setZeroes2(vector<vector<int>>& matrix) {
    //firt we need to create two vectors - row and col to store if that ith row or jth col has any
    //0 in it
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    /*first lets traverse the entire matrix and store:
        1. if any particular row has a zero -> store in 0th col
        2. if any particular col has a zero -> sotre this in 0th row
        3. M[0][0] is overlapping for both 0th row and 0th col, 
            so, M[0][0] will denote if 0th row has a zero and a variable
            col0 will denote if 0th col has a zero
    */
    int col0 = 1;
    for(int i = 0; i<m; i++){
        //for each row, first check if 0th col has a zero
        if(matrix[i][0] ==0) col0 = 0;
        for(int j = 1; j<n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    //now traverse the matrix in reverse
    for(int i = m-1; i>=0; i--){
        for(int j = n-1; j>=1; j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }                
        }
        //for every row, check for 0th col separately
        if(col0 == 0)matrix[i][0] = 0;
    }
}
int main()
{
    vector < vector < int >> arr;
    arr = {{1,1,1,1}, {1,0,1,1}, {1,1,0,1},{0,0,0,1}};
    setZeroes2(arr);
    cout<<"The Final Matrix is "<<endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
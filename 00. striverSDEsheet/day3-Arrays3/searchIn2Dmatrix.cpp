#include<iostream>
using namespace std;

bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    int i = 0, j = matrix[0].size() - 1;
    while(i<matrix.size() && j>=0){
        if(matrix[i][j] == target){
            return true;
        }
        else if(target > matrix[i][j]){
            //means go down 
            i++;
        }
        else{
            //go left 
            j--;
        }
    }
    return false;        
}
// O(log(m*n))
bool searchMatrixOptimal(vector<vector<int>>& matrix, int target){
    //apply binary search in the matrix from the index 0 to index m*n-1.
    //visualize the 2D matrix as a linear array of size m*n
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        int e = (m*n)-1;
        while(s<=e){
            int mid = (s + (e-s)/2);
            if(matrix[mid/n][mid%n] == target){
                return true;
            }
            else if(matrix[mid/n][mid%n] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return false;
    }
}

int main()
{
    return 0;
}
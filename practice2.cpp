#include<iostream>
#include<vector>
using namespace std;

void print(int n,int m){

    vector<vector<int>> arr(n,vector<int>(n,0));

    //4 variables
    int startRow = 0;
    int endRow = n - 1;
    int startCol = 0;
    int endCol = m - 1;

    int val = 1;

    //Outer Loop (Traverse array boundary)
    while(startCol<= endCol and startRow <=endRow){

        //Start Row
        for(int col = startCol ; col<=endCol; col++){
            arr[startRow][col] = val++;
        }

        //End Col
        for(int row=startRow + 1;row<=endRow;row++){
            arr[row][endCol] = val++;
        }

        //End Row
        for(int col=endCol - 1; col>=startCol;col--){
            if(startRow==endRow){
                break;
            }
            arr[endRow][col] = val++;
        }   

        //Start Col
        for(int row = endRow-1; row >=startRow + 1;row--){
            // Avoid Duplicate Printing of elements
            if(startCol==endCol){
                break;
            }
            arr[row][startCol] = val++;
        }

        //update the variables to point to inner spiral
        startRow++;
        endRow--;
        startCol++;
        endCol--;
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    print(n, n);
    return 0;
}
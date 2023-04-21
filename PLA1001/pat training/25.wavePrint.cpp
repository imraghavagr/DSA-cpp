#include<iostream>
#include<vector>
using namespace std;
void normalPrint(vector<vector<int>> &mat, int m, int n){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void wavePrint(vector<vector<int>> &mat, int m, int n){
    for(int j = 0; j<n; j++){
        //down to up  
        if(j&1){
            for(int i = m-1; i>=0; i--){
                cout<<mat[i][j]<<" ";
            }
        }
        //up to down 
        else{
            for(int i = 0; i<m; i++){
                cout<<mat[i][j]<<" ";
            }
        }
    }
    cout<<endl;
}
int main()
{   
    int m, n;
    cin>>m>>n;
    vector<vector<int>> mat(m, vector<int> (n));
    int x;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>x;
            mat[i][j] = x;
        }
    }
    normalPrint(mat, m, n);
    wavePrint(mat, m, n);
    return 0;
}
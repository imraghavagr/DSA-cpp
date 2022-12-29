#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int solve(vector<vector<int>> &v, int m, int n){
    if(m < 3 || n < 3)  return -1;
    int ans = INT_MIN;
    int sum;
    int ans_i,ans_j;
    for(int i = 0; i<m-2; i++){
        sum = 0;
        for(int j = 0; j<n-2; j++){
            sum = v[i][j] + v[i][j+1] + v[i][j+2] +v[i+1][j] + v[i+1][j+1] + v[i+1][j+2] + v[i+2][j] + v[i+2][j+1] + v[i+2][j+2];
            if(sum > ans){
                ans = sum;
                ans_i = i;
                ans_j = j;
            }
        }
    }
    cout<<v[ans_i][ans_j]<<" "<<v[ans_i][ans_j+1]<<" "<<v[ans_i][ans_j+2]<<endl;
    cout<<v[ans_i+1][ans_j]<<" "<<v[ans_i+1][ans_j+1]<<" "<<v[ans_i+1][ans_j+2]<<endl;
    cout<<v[ans_i+2][ans_j]<<" "<<v[ans_i+2][ans_j+1]<<" "<<v[ans_i+2][ans_j+2]<<endl;

    return ans;
}
int main()
{  
    int m,n;
    cin>>m,n;
    vector<vector<int>> v(m,vector<int>(n));
    int num;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>num;
            v[i][j] = num;
        }
    }
    cout<<solve(v, m, n)<<endl;
    return 0;
}
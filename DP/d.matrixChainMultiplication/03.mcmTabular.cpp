#include<iostream>
using namespace std;
int matrixMultiplication(int N, int arr[])
{
    // code here
    int dp[N][N];
    
    //if(i == j)    return 0;
    for(int i = 1; i<N; i++)    dp[i][i] = 0;
    
    for(int i = N-1; i>=1; i--){
        //but j is always greater than i .. so j should start from i+1
        for(int j = i+1 ; j<N; j++){
            int ans = 1e9;
            for(int k = i; k<j; k++){
                int tempAns = dp[i][k] + dp[k+1][j] + (arr[i-1]*arr[k]*arr[j]);
                ans = min(ans, tempAns);
            }
            dp[i][j] = ans;
        }
    }
    
    return dp[1][N-1];
}
int main()
{
    return 0;
}
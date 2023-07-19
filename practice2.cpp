/**
m,n,a,b
1. f(m,n) => lcs len if we take first m chars from str a and the first n chars from the str b
2. if(a[m-1] == b[n-1])
    else    reduce str a + reduce str b
            return max(c1,c2)
3. a = "", b = "pqr" => 0;
    if(m == 0 || n == 0)    return 0;

**/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// mbadm
// mdabm
// TC-> exponential => 2^n * 2^n
// SC -> ASS -> n
//f(5,5)
//f(4,4)
// f(3,4)  f(4,3)
int findLCS(int m, int n, string &a, string &b, vector<vector<int>> &dp)
{
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            // rec case
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    //dp[2][3] -> lcs that we can get if we take first 2 char from str a and first 3 chars from str b
    return dp[m][n];    
}
// 0 1 2 3 .. m 
// 0 1 2 3 .. n
// m*n
// T -> O(m*n) 
// S -> O(m*n) -> O(n)
int findMinInsertionsToMakePal(string &a)
{
    string b(a);
    reverse(b.begin(), b.end());
    if (a == b)
        return 0;
    int n = a.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int lenLCS = findLCS(n, n, a, b, dp);
    return n - lenLCS;
}

int main()
{
    string a;
    cin >> a;
    cout << findMinInsertionsToMakePal(a) << endl;
    return 0;
}
//https://codeforces.com/contest/189/problem/A
#include<iostream>
#include<climits>
using namespace std;
int cutRibbon(int* len, int N){
    int t[4][N+1];
    for(int j=0; j<N+1; j++){b
        t[0][j] = INT_MIN;
    }
    for(int i = 0; i<4; i++){
        t[i][0] = 0;
    }
    // for(int j=1;j<N+1; j++){
    //     if(j%len[0 == 0]){
    //         t[1][j] = j/len[0];
    //     }
    //     else{
    //         t[1][j] = INT_MIN;
    //     }
    // }
    //2nd row initialization is not mandatory. 

    //filling remaining cells
    for(int i =1; i<4; i++){
        for(int j=1; j<N+1; j++){
            if(len[i-1]<=j){
                t[i][j] = max(1 + t[i][j-len[i-1]],t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[3][N];

}
int main()
{   
    int N;
    int len[3];

    cin>>N;
    for(int i =0; i<3;i++){
        cin>>len[i];
    }
    cout<<cutRibbon(len,N)<<endl;
    return 0;
}
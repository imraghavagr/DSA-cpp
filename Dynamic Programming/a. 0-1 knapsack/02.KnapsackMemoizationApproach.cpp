//check this
//Recursive approach + Memoization = DP [Top Down Approach]
#include<iostream>
#include<cstring>
using namespace std;

int knapsack(int*wt, int*val, int n, int w){
    int static t[100][100];// since t is static, its initialization will be done only once
    memset(t,-1,sizeof(t));// set all values of t = -1

    if(n==0 || w == 0){
        return 0;
    }
    if(t[n][w] != -1){
        //if the answer for n,w is already found earlier, return it from the matrix
        return t[n][w];
    }
    //rec case
    if(wt[n-1] <= w){
        int choice1 = val[n-1] + knapsack(wt,val,n-1,w-wt[n-1]);
        int choice2 = knapsack(wt,val,n-1,w);
        //return the ans as well save it in the matrix for future usage.
        return t[n][w] = max(choice1,choice2);
    }
    else{
        //return the ans as well save it in the matrix for future usage.
        return t[n][w] = knapsack(wt,val,n-1,w);
    }
}
int main()
{   
    int val[] = {10,20,30};
    int wt[] =  {1,1,1};
    int w = 2; //knapsack capacity
    int n = sizeof(val)/sizeof(int);
    cout<<knapsack(wt,val,n,w)<<endl;
    return 0;
}
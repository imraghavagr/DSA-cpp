/*
https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#

Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.
*/
#include<iostream>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) 
{
    int t[1001][1001];
    
    //Intitialization
    for(int i = 0; i<n+1; i++){
        for(int j= 0; j<W+1; j++){
            if(i == 0 || j== 0){
                t[i][j] = 0;
            }
        }
    }
    
    //filling remaining cells
    for(int i = 1; i<n+1; i++){
        for(int j= 1; j<W+1; j++){
            if(wt[i-1] <= j){
                //two choices- either take this item or do not take this item- if we take the item once, we can take it again also
                t[i][j] =  max(val[i-1] +t[i][j-wt[i-1]],t[i-1][j]);
                
            }
            else{
                // weight of the item exceeds the knapsack capacity
                t[i][j] =  t[i-1][j];
            }       
        }
    }
    return t[n][W];
}

int main()
{   
    int val[] = {10,20,30};
    int wt[] =  {1,1,1};
    int w = 2; //knapsack capacity
    int n = sizeof(val)/sizeof(int);
    cout<<knapSack(w,wt,val,n)<<endl;
    return 0;
}
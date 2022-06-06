//exactly same as unbounded knapsack problem
//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#
#include<iostream>
using namespace std;
int cutRod(int price[], int n){
    //this is exactly same as unbounded knapsack question
    
    int length[n];
    for(int i = 0; i<n; i++){
        length[i] = i+1;
    }
    
    int t[n+1][n+1];
    //initialization
    for(int i =0; i<n+1; i++){
        for(int j =0; j<n+1; j++){
            if(i==0 or j==0){
                t[i][j] = 0;
            }
        }
    }
    
    //filling remaining cells
    for(int i =1; i<n+1; i++){
        for(int j =1; j<n+1; j++){
            if(length[i-1]<=j){
                //two choices- either take this element or do not take it 
                t[i][j] = max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][n];
}
int main()
{
    return 0;
}
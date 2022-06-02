//given an array of natural numbers and a sum value x;
//find the number of subsets of arr with sum equal to x.
//direct varation of subset sum problem
//0 is not present in the array
#include<iostream>
using namespace std;
int findNumSubsets(int* arr, int n, int sum){
    // code here 
    
    //declaring the matrix
    int  t[n+1][sum+1];
    //initialization
    for(int i = 0; i<n+1; i++){
        for(int j= 0; j<sum+1; j++){
            if(i==0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j]= 1;
            }
        }
    }
    
    //filling the remaining table
    
    for(int i =1; i<n+1; i++){
        for(int j= 1; j<sum+1; j++){
            
            //element is smaller than or equal to sum
            if(arr[i-1]<=j){
                //two choices- either take it or do not take it
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                //element is greater than sum 
                //do not take it    
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
}

int main()
{
    int arr[] = {2,3,5,6,8,10};
    int n = sizeof(arr)/sizeof(int);
    int sum = 10;
    cout<<findNumSubsets(arr,n,sum)<<endl;//3 for this input
    return 0;
}
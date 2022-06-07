/* Same as numberOfSubsets ques. Just add unbounded property.
https://practice.geeksforgeeks.org/problems/coin-change2448/1#
*/
#include<iostream>
using namespace std;
long long int count(int arr[], int n, int sum) {
    // code here.
    //declaring the matrix
    long long int t[n+1][sum+1];
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
                t[i][j] = t[i][j-arr[i-1]] + t[i-1][j];
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
    
    return 0;
}
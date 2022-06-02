//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
//given an array, and a sum , return true if there exists a subset of the array whose sum is equal to given sum value.
//T= O(sum*N)
#include<iostream>
#include<vector>
using namespace std;

bool isSubsetSumTabular(vector<int>arr, int sum){
    // code here 
    
    //declaring the matrix
    int static t[101][100001];
    //initialization
    for(int i = 0; i<arr.size()+1; i++){
        for(int j= 0; j<sum+1; j++){
            if(i==0){
                t[i][j] = false;
            }
            if(j==0){
                t[i][j]= true;
            }
        }
    }
    
    //filling the remaining table
    
    for(int i =1; i<arr.size()+1; i++){
        for(int j= 1; j<sum+1; j++){
            
            //element is smaller than or equal to sum
            if(arr[i-1]<=j){
                //two choices- either take it or do not take it
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                //element is greater than sum 
                //do not take it    
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[arr.size()][sum];
}

int main()
{
    vector<int> v = {3,34,4,12,5,2}; //ans = yes/1
    int sum = 9;
    cout<<isSubsetSumTabular(v,sum)<<endl;
    return 0;
}
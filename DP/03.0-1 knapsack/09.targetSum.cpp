/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/
//if we consider all the positive elements in one set and all the negative in second set, then 
//this question is exactly same as numberofSubsetsOfGivenDifference
#include<iostream>
using namespace std;
int countsubsets(int*arr, int n, int sum){
    int t[n+1][sum+1];
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i==0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j] = 1;
            }
        }
    }

    //filling remaining cells
    for(int i = 1; i<n+1; i++){
        //assuming the array does not contain 0
        for(int j = 1; j<sum+1; j++){
            if(arr[i-1]<=j){
                t[i][j] =  t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int countSubsetDiff(int*arr,int n, int d){
    //we need to find all possible ways, s.t. sum(s1)-sum(s2) = d
    //sum(s1)-sum(s2) = d...(1)
    //sum(s1)+sum(s2) = sum(arr) ...(2)
    //On adding 1 and 2, sum(s1) = (d+sum[arr])/2
    //now the question changed to- count the number of subsets of given sum...
    //therefore here, we just need to find the number of subsets of sum(s1)

    //finding sum(arr)
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+=arr[i];
    }
    int sumS1 = (d+sum)/2;

    return countsubsets(arr,n,sumS1);
}
int main()
{
    int arr[] = {1,1,2,3};
    int n = sizeof(arr)/sizeof(int);
    int diff = 1;
    cout<<countSubsetDiff(arr,n,diff)<<endl;
    return 0;
}
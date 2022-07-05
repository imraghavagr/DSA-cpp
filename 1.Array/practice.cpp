#include<iostream>
#include<climits>
using namespace std;
int main(){
    
    int arr[] = {-4,1,3,-2,6,2,-1,-4,-7};
    int n = sizeof(arr)/sizeof(int);

    //O(n^3) approach
    int maxSum = 0;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int currSum = 0;
            for(int k = i; k<=j; k++){
                currSum += arr[k];
            }
            if(currSum>maxSum){
                maxSum = currSum;
            }
        }
    }
    cout<<maxSum<<endl;
    //O(n^2) approach
    //first lets make the csum array 
    int csum[n];
    csum[0] = arr[0];
    cout<<csum[0]<<" ";
    for(int i = 1; i<n; i++){
        csum[i] =csum[i-1]  + arr[i];
        cout<<csum[i]<<" ";
    }
    cout<<endl;
    
    int maxAns = INT_MIN;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            //lets find out the sum of elements between 
            //idx i and j
            int currSum = (csum[j] - csum[i]) + arr[i];
            maxAns = max(maxAns,currSum);
        }        
    }
    cout<<maxAns<<endl;

    //third approach - kadane's algo
    //maintain two variables- currSum, maxSumSoFar
    for(int i )


    return 0;
}
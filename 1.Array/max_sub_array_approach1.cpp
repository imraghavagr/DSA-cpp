#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main() {
    int a[] = {-4,1,3,-2,6,2,-1,4,-7};
    //int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(int);
    int maxSum = 0;
    int left,right;
    for(int i =0; i<n; i++){
        for(int j =i; j<n; j++){
            //we got all possible pairs of i and j
            //print the continuos numbers between those pairs
            int sum = 0;
            for(int k = i; k<=j; k++){
                sum += a[k];
                //cout<<a[k]<<",";
            }
            //cout<<" ";
            //maxSum = max(sum,maxSum);
            if(sum>maxSum){
                maxSum = sum;
                left = i;
                right = j;
            }
        }
        //cout<<endl;
    }
    cout<<maxSum<<" for the following array: "<<endl;
    for(int i = left; i<=right; i++){
        cout<<a[i]<<" ";
    }
}

        



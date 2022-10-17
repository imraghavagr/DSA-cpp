//https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/0

//512gb - with watch - 1.4l... 

//512 gb - with watch - 1l 4 thousand + [2500]charger - insurance 1 yr - student id ???
//
#include<iostream>    
using namespace std;
long maximumSumSubarray(int K, vector<int> &Arr , int N){
    // sliding window problem 
    long sum = 0;
    long ans = INT_MIN;
    int i = 0;
    int j = 0;
    while(j<N){
        sum += Arr[j];
        //make the window of size k
        if((j-i)+1 < K){
            // sum += Arr[j];
            j++;
        }
        else if((j-i)+1 == K){
            
            ans = max(ans,sum);
            
            //slide the window by one step
            i++;
            j++;
            //update the window sum
            sum = sum - Arr[i-1];
        }
    }
    return ans;
}
int main()
{
    return 0;
}
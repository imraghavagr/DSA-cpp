#include<iostream>
#include<algorithm>
using namespace std;
bool isPossible(int mid, int* arr, int n){
    for(int i = 0; i<n; i++){
        int currr_height = 
    }
}
int main()
{   
    int arr[] = {6,2,5,4,5,1,6};
    
    int s = 1;
    int n = sizeof(arr)/sizeof(int);
    
    int maxElem = arr[0];
    
    for(int i = 1;i<n ; i++){
        maxElem = max(arr[i,maxElem]);
    }
    int r = maxElem*n;
    int mid;
    int ans;
    while(s<=e){
        mid = (s+e)/2;
        if(isPossible(mid,arr,n)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
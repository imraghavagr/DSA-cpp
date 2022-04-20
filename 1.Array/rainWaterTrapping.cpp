#include<iostream>
#include<algorithm>
using namespace std;
void getMXL(int* maxL,int* arr, int n){
    maxL[0] = arr[0];
    for(int i = 1; i<n; i++){
        maxL[i] = max(maxL[i-1],arr[i]);
    }
}
void getMXR(int* maxR,int* arr, int n){
    maxR[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--){
        maxR[i] = max(maxR[i+1],arr[i]);
    }
}
int trapWater(int* arr, int n){
    
    int maxL[n];
    int maxR[n];
    int water[n];

    getMXL(maxL,arr,n);
    getMXR(maxR,arr,n);
    int sum = 0;
    for(int i = 0; i<n; i++){
        water[i] = min(maxL[i],maxR[i])-arr[i];
        sum += water[i];
    }
    return sum;
}
int main()
{   
    int arr[] = {3,0,0,2,0,4};
    int n = sizeof(arr)/sizeof(int);
    cout<<trapWater(arr,n)<<endl;
    return 0;
}
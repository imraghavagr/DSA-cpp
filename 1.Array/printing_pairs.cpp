#include<iostream>
using namespace std;
/*
i/p = 1,2,3,4
o/p = 
(1,2) (2,3) (3,4)
(1,3) (2,4)
(1,4) 
*/
void printPairs(int *arr, int n){
    for(int i = 0; i<n-1; i++){
        for(int j= i+1; j<n; j++){
            cout<<"("<<arr[i]<<","<<arr[j]<<")"<<" ";
        }
        cout<<endl;
    }

}
int main(){

    int arr[] = {10,20,30,40,50,60};
    int n = sizeof(arr)/sizeof(int);

    //print all the elemetns
    for(int x : arr){
        cout<< x<<" ";
    }
    cout<<endl;
    printPairs(arr,n);
    
    return 0;
}
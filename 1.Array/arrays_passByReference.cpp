#include<iostream>
using namespace std;
void fun(int *arr, int n){

    cout<<"Inside function"<<endl;
    cout<<sizeof(arr)<<endl; //different because here arr is a pointer
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
int main(){
    
    int arr[] = {100,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    cout<<"Inside main"<<endl;
    cout<<sizeof(arr)<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    fun(arr,n);
    return 0;

}
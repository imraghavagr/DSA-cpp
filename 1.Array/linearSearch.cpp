#include<iostream>
using namespace std;
//time complexity
/*
In worst case, 
we will search till the last element in the array.
therefore O(n).
*/
int linearSearch(int *arr, int n, int key){

    for (int i = 0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    //key not found
    return -1;

}
int main(){ 
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    int idx = linearSearch(arr, n, key);
    if(idx!=-1){
        cout<<idx<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }
    return 0;
}
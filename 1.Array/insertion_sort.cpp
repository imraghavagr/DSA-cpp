#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
space -
Time:
cuurrently we are at i = 1, and the left of it is sorted .. 
Insert the element at current i in its currect position in the sorted array. 

*/
void insertionSort(vector<int> &arr){
    //1 element already sorted 
    //sort remaining n-1 elements from i = 1 to n-1
    for(int i =1; i<arr.size(); i++){
        //taking the element at curr i idx and inserting it in its correct position in the sorted array.
        int j = i-1;
        int temp = arr[i];
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]= temp;
    }
}
int main()
{
    vector<int> v{1,2,3,4,5};
    insertionSort(v);
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
space - O(1)
Time -  O(n^2) in both best and worst case
- We find the max element in the array and place it in its correct position at the end
- or we find the min element in the array and place it int its correct pos at the begining.
            4 5 1 2 3
4 3 1 2 5      or         1 5 4 2 3 [placed smallest element at idx 0 ]
2 3 1 4 5                 1 2 4 5 3 [placed smallest elem at indx 1] 
2 1 3 4 5                 1 2 3 5 4 [placed smallest elem at indx 2]
1 2 3 4 5                 1 2 3 4 5 [placed smallest elem at indx 3]
                                    [the last element is automatically at correct idx/pos]
*/

void insertionSort(vector<int> &arr){
    //for ascending order
    int n = arr.size();
    int minidx;
    for(int i = 0; i<n-1; i++){
        //we will place currect element at idx i 
        // basically select and swap the min element in the unsorted array with the i th index element
        minidx = i; //assumption
        //finding smallest element in the array
        for(int j =i; j<n; j++){
            if(arr[j]<arr[minidx]){ minidx = j; }
        }
        //swap the minelem with the currect i 
        swap(arr[i], arr[minidx]);
    }
}
int main()
{
    vector<int> v{4,5,1,2,3};
    insertionSort(v);
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
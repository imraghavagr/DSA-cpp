#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
space - O(1)
Time -  O(n^2) in both best and worst case
- We find the max element in the array and place it in its correct position
4 5 1 2 3
4 3 1 2 5
2 3 1 4 5
2 1 3 4 5
1 2 3 4 5
*/

void insertionSort(vector<int> &arr){
   
    for(int i =0; i<arr.size(); i++){
        //find the max element in the cuure array and place it in its correct step
        int last = arr.size()-i-1;

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
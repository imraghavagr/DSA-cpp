#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
space - O(1)
Time:
Best Case(array is already sorted) - O(n) -  for this add extra implementation 
                                             if there is no swap happening for all values of j in the first pass that is for i = 0,
                                             break the loop

Worst Case(array is sorted in opposite order) - O(n^2)
*/
void bubbleSort(vector<int> &arr){

    //take n-1 elements to the end
    bool swapped = false;
    for(int i = 0; i<arr.size()-1; i++){
        for(int j = 1;j<arr.size()-i;j++){
            if(arr[j]<arr[j-1]){
                swap(arr[j], arr[j-1]);
                swapped = true;
            }
        }
        if(!swapped){break;}
    }

}
int main()
{
    vector<int> v{1,2,3,4,5};
    bubbleSort(v);
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
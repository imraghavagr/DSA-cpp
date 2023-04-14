#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int> &arr){
    int n = arr.size();
    bool swapHappened = false;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapHappened = true;
            }
        }
        if(swapHappened == false)   break;
    }
}
int main()
{
    vector<int> arr{5,4,3,2,1};
    vector<int> arr2{1,2,3,4,5};
    for(auto it : arr2)  cout<<it<<" ";
    cout<<endl;
    bubbleSort(arr2);
    for(auto it : arr2)  cout<<it<<" ";
    cout<<endl;
    return 0;
}
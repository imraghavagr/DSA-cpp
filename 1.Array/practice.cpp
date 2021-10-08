#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bubbleSort(vector<int> &arr){

    //take n-1 elements to the end
    for(int i = 0; i<arr.size()-1; i++){
        for(int j = 1;j<arr.size()-i;j++){
            if(arr[j]<arr[j-1]){
                swap(arr[j], arr[j-1]);
            }
        }
    }

}
int main()
{
    vector<int> v{5,4,3,2,1};
    bubbleSort(v);
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
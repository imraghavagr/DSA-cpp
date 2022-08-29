#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//N = n1(size of a1) + n2 (size of a2)

//O(n1) for traversal of a1 * O(n2logn2) sorting the array a2 of size n2
void mergeAndSort1(vector<int> &a1,vector<int> &a2){
    for(int i = 0; i<a1.size(); i++){
        //compare this element with the 0th element of a2 array
        if(a1[i]>a2[0]){
            swap(a1[i],a2[0]);
            //but now a2 is unsorted, so sort it again
            sort(a2.begin(),a2.end());
        }
    }
}
int main()
{   
    vector<int> a1 = {1,4,7,8,10};
    vector<int> a2 = {2,3,9};
    mergeAndSort1(a1,a2);
    for(int x : a1){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int x : a2){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}

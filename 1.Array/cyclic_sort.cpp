#include<iostream>
#include<vector>
using namespace std;
/*
When elements are given in range 1 to n, use cyclic sort.
for eg for n = 5,
array = 2, 3, 1, 4, 5 (means all elements from 1 to n must be present once, but they are unsorted )
3 2 1 4 5
1 2 3 4 5
0 1 2 3 4
*/
void cyclicSort(vector<int> &v){
    int i =0;
    while(i<v.size()){
        int correctIdx = v[i] - 1; // correctidx = value - 1
        if(i != correctIdx){    // check if the current idx == correct idx
            swap(v[i], v[correctIdx]);
            correctIdx = v[i] - 1;
        }
        
        if(i == correctIdx){
            i++;
        }
    }
}
void sort1(vector<int> &v){
    int i = 0;
    while(i<v.size()){
        int correct  = v[i] - 1;
        if(v[i] != v[correct]){
            swap(v[i],v[correct]);
        }
        else{
            i++;
        }
        
    }
}
int main(){

    vector<int> v{0,3,2,1,4};
    //cyclicSort(v);
    sort1(v);
    for(auto x :  v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
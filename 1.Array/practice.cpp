#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int max_subarray_sum(vector<int> arr) {
    int cs= 0; 
    int ms = 0;
    for(int x : arr){
        cs += x;
        if(cs<0){
            cs = 0;
        }
        ms = max(cs,ms);
    }
    return ms;
}
int main(){
    vector<int> a{-4,1,3,-2,6,2,-1,-4,-7};
    int ans = max_subarray_sum(a);
    cout<<ans<<endl;
    return 0;
}
//https://www.interviewbit.com/problems/perfect-peak-of-array/
#include<iostream>
#include<vector>

using namespace std;
/*
5, 1, 4, 3, 6, 8, 10, 7, 9
once such elemetn- 6 exists, therefore o/p = 1
*/

int perfectPeak(vector<int> &A) {
    bool left;
    bool right;
    for(int i = 1; i<A.size()-1; i++){
        //cout<<"Checking for "<<A[i]<<endl;
        left = true;
        right = true;
        //check for all the elements at the lest of the array
        for(int j = i-1; j>=0; j--){
            if(A[j]>=A[i]){
                left = false;
                break;
            }
        }
        //cout<<left<<endl;
        //check for all the elements at the right of the array
        for(int j = i+1; j<A.size(); j++){
            if(A[j]<=A[i]){
                right = false;
                break;
            }
        }
       // cout<<right<<endl;
        if(left && right){
            return 1;
        }
        cout<<endl<<endl;

    }
    return 0;
    
}

int main(){
    
    vector<int> v{1, 2, 3, 4, 5, 4, 3, 2, 3, 10};
    int ans = perfectPeak(v);
    cout<<ans<<endl;
    return 0;
}
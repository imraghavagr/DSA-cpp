//https://www.interviewbit.com/problems/woodcutting-made-easy/
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll func(vector<int> &A, ll mid){
    ll sum = 0;
    for(int i = 0; i<A.size(); i++ ){
        if(A[i] > mid){
            sum += A[i]-mid;
        }
    }
    return sum;
}
int  solve(vector<int> &A, int B) {
    ll start = 0;
    ll end = *max_element(A.begin(), A.end());
    //cout<<end<<endl;
    ll mid;
    ll wood_obt;
    while(start<=end){
        mid = start + (end-start)/2;
        wood_obt = func(A,mid);
        if(start == mid or wood_obt == B){
            return mid;
        }
        else if(wood_obt > B){
            start = mid;
        }
        else{
            end = mid;
        }
    }
    return mid;
}

int main(){

    vector<int> v{114, 55, 95, 131, 77, 111, 141};
    int B = 95;
    cout<<solve(v,B)<<endl;
    return 0;
}
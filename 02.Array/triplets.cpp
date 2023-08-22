#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
// O(N^2) time
//0.053365 0.060393 0.128168 0.197118 0.203301 0.264731 0.297657 0.375614 0.420048 0.437979 
int solve(vector<string> &A) {
    sort(A.begin(), A.end());
    for(int i = 0; i<A.size()-2; i++){
        //current i is the idx of first fixed index 
        int l = i+1;
        int r = A.size()-1;        
       while(l<r){
            double d = stod(A[i])+stod(A[l])+stod(A[r]);
            ///cout<<d<<endl;
            if(d > 1 && d <2){
                return 1;
            }
            else if(d < 1){
                l++;               
            }
            else if(d > 2){
                r--;
            }
        }
    }
    return 0;
}
int main(){

    vector<string> A{"0.297657", "0.420048", "0.053365", "0.437979", "0.375614", "0.264731", "0.060393", "0.197118", "0.203301", "0.128168"};
    //vector<double> v{0.6, 0.7, 0.8, 1.2, 0.4};
    int x = solve(A);
    cout<<x<<endl;
    return 0;
}
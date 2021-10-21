#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
void bubbleSort(vector<int> v){
    bool bestCase = true;
    int n = v.size();
    for(int i =0; i<n-1; i++){
        for(int j = 1; j<=n-1-i; j++){
            if(v[j-1]>v[j]){
                swap(v[j-1],v[j]);
                bestCase = false;
            }
        }
        if(bestCase){
            return;
        }
    }
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}
int main(){

    vector<int> v{5,4,3,2,1};
    bubbleSort(v);
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    
    return 0;
}
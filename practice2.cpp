#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmpr(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
int main()
{   
    // // vector<pair<int,int>> v = {{1,2},{8,3},{5,6}};
    // vector<int> v = {1,2,3,4,5};
    // // sort(v.begin(), v.end(), compare);
    // sort(v.rbegin(), v.rend());
    vector<vector<int>> v = {{5,2,3},{20,3,4},{15,4,5}};
    sort(v.begin(), v.end(), cmpr);
    for(auto x : v){
        for(auto val : x)   cout<<val<<",";
        cout<<" ";
    }
    cout<<endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int main()
{   
    vector<int> v = {12, 15, 10, 9, 7, 8, 3, 4};
    vector<int> ans;
    ans.push_back(v[v.size()-1]);
    for(int i = v.size()-2; i>=0; i--){
        if(v[i] > ans[ans.size()-1]){
            ans.push_back(v[i]);
        }
    }
    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
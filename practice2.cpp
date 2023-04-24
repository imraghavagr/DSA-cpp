#include<iostream>
#include<vector>
using namespace std;
void solve(int i, vector<int> &arr, int target, vector<int> &ans){
    //base case 
    if(i == arr.size()) return;

    //induction step
    if(target == arr[i]){
        ans.push_back(i);
    }
    //hyposthesis 
    solve(i+1, arr, target, ans);
}
int main()
{   
    vector<int> arr = {1,2,3,4,2,5};
    int target = 2;
    vector<int> ans;
    solve(0, arr, target, ans);
    for(int x : ans)    cout<<x<<" ";
    cout<<endl;
    return 0;
}
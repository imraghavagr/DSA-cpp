#include<bits/stdc++.h>
using namespace std;
int main()
{   
    vector<int> arr = {20,30,40,40,40,50,100,1100};
    int key = 35; 
    int idx = lower_bound(arr.begin(), arr.end(), key) - arr.begin();
    cout<<idx<<endl;
    idx = upper_bound(arr.begin(), arr.end(), key) - arr.begin();
    cout<<idx<<endl;
    return 0;
}
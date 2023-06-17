#include<bits/stdc++.h>
using namespace std;
int main()
{   
    vector<int> v = {1,2,3,4,5};
    int idx = upper_bound(v.begin(), v.end(), 4) - v.begin();
    cout<<idx<<endl;
    return 0;
}
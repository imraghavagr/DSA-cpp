#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x;
    vector<int> v;
    for(int i = 0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
    int ans = v[0];
    for(int i = 1; i<v.size(); i++){
        ans = ans^v[i];
    }

    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{   
    string str = "101";
    vector<string> permu;
    for(int i = 0; i < str.size(); i++)
        permu.push_back(str.substr(i) + str.substr(0, i));
    for(auto x : permu){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
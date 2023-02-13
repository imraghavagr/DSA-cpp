#include<bits/stdc++.h>
using namespace std;
int main()
{  
    vector<int> v {3,4,4,5,4,2,4};
    // vector<int> v {1,2,3,4,5,1};
    unordered_map<int,int> mp;
    int maxFreq = 0;
    int maxFreqElement = -1;
    for(int i = 0; i<v.size(); i++){
        mp[v[i]]++;
        if(mp[v[i]] > maxFreq){
            maxFreqElement = v[i];
            maxFreq = mp[v[i]];
        }
    }
    if(mp[maxFreqElement]>v.size()/2){
        cout<<maxFreqElement<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return 0;
}
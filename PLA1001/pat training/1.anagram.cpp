#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool solve(string a, string b){
    
    if(a.length() != b.length())    return false;

    unordered_map<char, int> mp;

    for(auto it : a){
        mp[it]+=1;
    }
    int count = mp.size();
    for(auto it : b){
        if(mp.find(it) == mp.end()){
            return false;
        }
        else{
            mp[it]--;
            if(mp[it] == 0) count--;
        }
    }
    return count == 0;
}
int main()
{   
    string a,b;
    cin>>a>>b;
    cout<<solve(a,b)<<endl;
    return 0;
}
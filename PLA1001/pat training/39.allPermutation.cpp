#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve2(string s, int index, vector<string> &ans){
    if(index == s.length()-1){
        ans.push_back(s);
        return;
    }
    for(int i = index; i<s.length(); i++){
        //swap value at index with all i 
        swap(s[index], s[i]);
        solve2(s, index+1, ans);
    }
}
int main()  
{   
    string s = "ABC";
    vector<string> ans;
    solve2(s,0,ans);
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
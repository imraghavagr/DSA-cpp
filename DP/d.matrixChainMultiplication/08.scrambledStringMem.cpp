//https://leetcode.com/problems/scramble-string/
#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string,int> mp;

bool solve(string a, string b){
    //base case
    //control reaches here only if len(a) == len(b)
    if(a.compare(b) == 0)   return true;
    if(a.length()<=1)   return false; // len of a and b are same, so no need to check for b

    //memoization code
    string temp = a + ' ' + b;
    
    if(mp.find(temp) != mp.end()){
        return mp[temp];
    }
    
    //rec case
    bool flag = false;
    int n = a.length();

    for(int i = 1; i<=n-1; i++){
        //two cases- 1. swap 2. No swap
        bool case1 = solve(a.substr(0,i), b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i));
        bool case2 = solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i));
        if(case1 || case2){
            flag = true;
            break;
        }
    }
    return mp[temp] = flag;
}

bool isScramble(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    if(m!=n)  return false;
    if(m==0 && n==0)    return true;
    
    mp.clear();
    return solve(s1,s2);
}
int main()
{   
    string s1,s2;
    cin>>s1>>s2;
    cout<<isScramble(s1,s2)<<endl;
    return 0;
}
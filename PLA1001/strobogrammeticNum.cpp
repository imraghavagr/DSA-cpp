#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool strobogrammeticNumberCheck(string str){
    
    unordered_map<char,char> mp;
    mp['0'] = '0';
    mp['1'] = '1';
    mp['6'] = '9';
    mp['8'] = '8';
    mp['9'] = '6';

    int s = 0;
    int e = str.length()-1;
    while(s<=e){
        if(mp.find(str[s]) == mp.end() || mp[str[s]] != str[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}
//another approach 
//reverse the number 
//then rotate the number 

int main()
{   
    string s;
    cin>>s;
    if(strobogrammeticNumberCheck(s)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}
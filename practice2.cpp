#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{   
    string s = "My name is Raghav";
    
    string word = "";

    for(int i = s.length()-1; i>=0; i--){
        if(s[i] != ' '){
            word += s[i];
        }
        else{
            reverse(word.begin(), word.end());
            cout<<word<<" ";
            word = "";
        }
    }
    reverse(word.begin(), word.end());
    cout<<word<<endl;
    return 0;
}
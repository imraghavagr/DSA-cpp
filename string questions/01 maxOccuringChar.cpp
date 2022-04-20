#include<iostream>
#include<string>
using namespace std;
char soln(string s){
    int freq[256] = {0};
    int max = -1;
    char ans;
    for(int i = 0; i<s.length(); i++){
        freq[s[i]]++;
        if(max<freq[s[i]]){
            max = freq[s[i]];
            ans = s[i];
        }
    }
    return ans;
}

int main()
{
    string s = "Raghav";
    cout<<soln(s)<<endl;
    return 0;
}
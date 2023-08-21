#include<iostream>
using namespace std;
string reverseWords(string s) {
    //without extra space 
    reverse(s.begin(), s.end());
    int read = 0, write = 0; 
    int cnt = 0; 
    for(int read = 0; read < s.length(); read++){ 
        if(s[read] == ' '){
            if(cnt > 0){
                reverse(s.begin()+(write-cnt), s.begin()+write);
                cnt = 0;
                s[write++]  = ' ';
            }
            while(s[read] == ' '){
                read++;
            }
        }
        if(read == s.length()){
            write--;
            continue;
        }
        s[write++] = s[read];
        cnt++;
        
    }
    reverse(s.begin()+(write-cnt), s.begin()+write);
    s.erase(s.begin()+write, s.end());
    return s; 
}
int main()
{
    return 0;
}
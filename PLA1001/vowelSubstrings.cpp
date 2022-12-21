#include<iostream>
#include<set>
using namespace std;
bool checkIfVowel(char ch){
    if(ch == 'a' || ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u'){
        return true;
    }
    return false;
}
int countVowelSubstrings(string s){
    if(s.length() < 5)
        return 0;

    int cnt = 0;
    set<char> st;
    int i = 0;
    while(i<s.length()){

        if(checkIfVowel(s[i])){
            st.insert(s[i]);
            if(st.size() == 5){
                cnt++;
        }
        }
        else{
            st.clear();
        }
        i++;
    }
    return cnt;
}

int main()
{   
    string s;
    cin>>s;
    cout<<countVowelSubstrings(s)<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int numDifferentIntegers(string word) {
    unordered_set<int> st;
    for(int i = 0; i<word.length(); i++){
        //if we find a digit.. we will keep on incrementing i untill we are finding digit 
        if(isdigit(word[i])){
            int num = 0; 
            while(isdigit(word[i])){

                num = (num*10) + (word[i]-'0');
                i++;
            }
            // cout<<num<<endl;
            st.insert(num);   
        }
    }
    return st.size();
}
int main()
{   
    string s = "a123bc34d8ef34";
    cout<<numDifferentIntegers(s)<<endl;
    return 0;
}
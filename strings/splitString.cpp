#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main()
{   
    string s, str;
    vector<string> v;
    s = "hello my name is Raghav Agarwal";

    // ss is an object of stringstream that references the S string.  
    stringstream ss(s); 

    // Use while loop to check the getline() function condition.  
    while (getline(ss, str, ' ')) {
        // `str` is used to store the token string while ' ' whitespace is used as the delimiter.
        cout<<str<<"*";
        v.push_back(str);
    }
    cout<<endl;
    for(auto it : v)    cout<<it<<"*";
    cout<<endl;

    return 0;
}
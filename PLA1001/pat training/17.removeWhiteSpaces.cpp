//given a string remove all the white spaces from it 
#include<iostream>
using namespace std;
string solve(string s){
    string temp;
    for(auto it : s){
        if(it != ' '){
            temp.push_back(it);
        }
    }
    return temp;
}
int main()
{   
    string s;
    getline(cin, s);
    cout<<solve(s)<<endl;
    return 0;
}
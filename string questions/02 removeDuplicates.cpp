#include<iostream>
#include<string>
#include<stack>

using namespace std;

string soln1(string s){
    //using string.find() STL function
    string str;
    for(int i = 0; i<s.length(); i++){
        int idx = str.find(s[i]);
        if(idx == -1){
            //this means that it is coming for the first time
            str += s[i];
        }
    }
    return str;
}
string soln2(string s){
    // "Raghhhavvv"
    //  0123456789
    string ans;
    for(int i = 0; i<s.length(); i++){
        bool take_this_char = true;
        for(int j = i-1;j>=0;j--){
            if(s[i] == s[j]){
                //this means that this char has appeared earlier, hence no need to add it in the ans
                take_this_char = false;
                break;
            }
        }
        if(take_this_char){
            ans += s[i];
        }
    }
    return ans;
}

//since this can be done in O(n2) by brute force and the inner loop depends upon outer loop
//this must be solved by stack also 
string soln3(string s){
    stack<char> s;
    for(int i = s.length()-1; i>=0; i--){
        //traverse the string from right to left
        //if the current element is already present at top
    }
}

int main()
{
    string s = "Raghhhavvv";
    cout<<soln1(s)<<endl;
    cout<<soln2(s)<<endl;
    return 0;
}
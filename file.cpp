#include<bits/stdc++.h>
using namespace std;

int main()
{   
    string A = "my name is Raghav";
    string ans; 
    int i = A.size()-1; 
    while(i >= 0){
        //form word by word 
        //skip all white spaces 
        while(i>=0 && A[i] == ' ')  i--; 
        
        string temp; 
        while(i>=0 && A[i] != ' '){
            temp.push_back(A[i]);
            i--;
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        ans.push_back(' ');
        i--;
    }
    ans.pop_back();
    cout<<ans<<endl;
    return 0;
}
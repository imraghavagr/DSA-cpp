#include<iostream>
#include<string>
using namespace std;
//just make the recursive tree using ip-op method.. then writing the code will be a piece of cake. 
void solve(string ip, string op){
    if(ip.length() == 0){
        cout<<op<<" ";
        return;
    }
    
    //now make two outputs .. 
    string op1 = op;
    string op2 = op;

    //choice - choose s[0] or not 
    //if we are choosing s[0], op will change 
    op2.push_back(ip[0]);
    
    //now reduce the input - by erasing the char at 0th index
    ip.erase(ip.begin()+0);

    //now again make two recursion calls 
    solve(ip, op1);
    solve(ip, op2);
}
int main()
{   
    string s;
    cin>>s;
    string op = "";
    solve(s,op);
    return 0;
}
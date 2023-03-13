#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void solve(string ip, string op){
    if(ip.length() == 0){
        cout<<op<<" ";
        return;
    }
    string op1 = op;
    string op2 = op;
    //we have two choices

    //take with case change 
    op1.push_back(toupper(ip[0]));
    //take without case change
    op2.push_back(ip[0]);

    // now make input smaller 
    ip.erase(ip.begin()+0);

    solve(ip, op1);
    solve(ip, op2);
}
int main()
{   
    string ip = "ab";
    string op = "";
    solve(ip, op);
    cout<<endl;
    return 0;
}
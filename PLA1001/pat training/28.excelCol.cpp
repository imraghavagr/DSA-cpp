#include<iostream>
using namespace std;
int solve(string ip, int i){
    if(i == 0){
        return ip[i] - 'A' + 1;
    }
    //value for current char 
    int val = ip[i]-'A' + 1;
    return val + 26*solve(ip, i-1);
}
int main()
{
    string ip;
    cin>>ip;
    cout<<solve(ip,ip.length()-1);
    return 0;
}
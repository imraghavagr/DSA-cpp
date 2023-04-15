#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{   
    string s;
    cin>>s;
    int cntStar = 0;
    int cntHash = 0;
    for(char ch : s){
        if(ch == '*')   cntStar++;
        else if(ch == '#')  cntHash++;
    }
    if(cntStar == cntHash)  cout<<0<<endl;
    else if(cntStar > cnth) cout<<1<<endl;
    else cout<<-1<<endl;
    return 0;
}
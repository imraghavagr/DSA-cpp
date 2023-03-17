#include<queue>
#include<iostream>
using namespace std;
int main()
{   
    queue<string> q;
    string s = "1";
    q.push(s);
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++){
        auto it = q.front();
        cout<<it<<" ";
        q.pop();
        q.push(it+'0');
        q.push(it+'1');
    }
    cout<<endl;
    cout<<q.size()<<endl;
    
    return 0;
}
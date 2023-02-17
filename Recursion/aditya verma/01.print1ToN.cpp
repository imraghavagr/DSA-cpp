#include<iostream>
using namespace std;
void solve(int n){
    if(n == 0){
        return;
    }
    solve(n-1);
    cout<<n<<" ";
}
int main()
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}
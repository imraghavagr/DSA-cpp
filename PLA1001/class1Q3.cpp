/*

*/
#include<iostream>
using namespace std;
int main()
{   int target;
    int ans = 0;
    cin>>target;
    
    int n;
    cin>>n;
    int sum = n;
    while(sum <= target){
        cin>>n;
        sum += n;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
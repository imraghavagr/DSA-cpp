#include<iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    int cnt = 0;
    int tempNum = n;
    while(tempNum>0){
        int ld = tempNum%10;
        if(ld != 0 && n%ld == 0){
            cnt++;
        }
        tempNum /= 10;
    }
    cout<<cnt<<endl;
    return 0;
}
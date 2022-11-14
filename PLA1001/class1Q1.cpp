/*

*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int temp = n;
    int len = 0;
    while(temp > 0){
        temp = temp/10;
        len++;
    }
    if(len != 3){
        cout<<"NO";
    }
    else{
        //lets find the middle number now 
        int middleNum = n/10;
        middleNum = middleNum%10;
        if(middleNum % 3 == 0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
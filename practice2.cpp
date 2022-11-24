#include<iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;

    for(int i = 1; i<=n; i++){
        //for each row, num of cols <= row num
        //print 1 and 0 alternatively
        int val = 1;
        for(int j = 1; j<=i; j++){
            if(j&1){
                cout<<1<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int fristVal = 1;
    int x = (n*n)+1;
    int y = 0;
    int secondVal = n*n + 1;
    int val = n*n + 1;
    int counter = 1;
    for(int i = 4; i>=1; i--){
        //first i cols 
        for(int j = 1; j<=i; j++){
            cout<<fristVal++<<"*";
        }
        //last i cols 
        // int val = x-y;
        int j;
        for(j = 1; j<=i; j++){
            if(j==i){
                cout<<secondVal++;
            }
            else{
                cout<<secondVal++<<"*";
            }
        }
        secondVal = val - (n-counter);
        counter++;
        val = secondVal;
        cout<<endl;
    }
    return 0;
}
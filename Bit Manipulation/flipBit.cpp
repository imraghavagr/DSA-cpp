// https://www.geeksforgeeks.org/find-longest-sequence-1s-binary-representation-one-flip//
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int pl = 0, cl = 0, ml = 0;
    while(n>0){

        if(n&1){
            cl++;
        }
        else{
            if(n&2 == 0){
                pl = 0;
            }
            else{
                pl = cl;
            }
            cl = 0;
        }
        ml = max(ml, cl+pl);
        n >>= 1;
    }
    cout<<ml+1<<endl;
    return 0;
}
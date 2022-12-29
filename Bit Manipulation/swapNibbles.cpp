#include<iostream>
using namespace std;
int solve(int n){
    
    //0x0F -> 0x is syntax kind of while writing hexa decimals
    //        0F means first four bits 0 and then four bits will be binary of hexadecimal F
    //        F -> 15 -> 1111 
    //        therefore, 0x0F = 00001111
    //similarly, 0xF0 -> 11110000

    int leftNibble = n&0x0F;
    int rightNibble = n&0xF0;
    //shift the nibbles so that they can be merged as reversed
    leftNibble <<=4;
    rightNibble >>=4;

    return leftNibble+rightNibble;
}
int main()
{   
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}
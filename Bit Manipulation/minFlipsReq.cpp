//https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
#include<iostream>
using namespace std;

//iterate through each bit 
//Time - O(LogN) // because maximum number of bits in a number is Log N
int minFlips(int a, int b, int c) {
    int ans = 0;
    int reqBit, bitInA, bitInB;
    while(a > 0 || b > 0 || c>0){
        reqBit = (c & 1);
        bitInA = (a & 1);
        bitInB = (b & 1);
        if(reqBit == 0){
            ans += (bitInA + bitInB);
        }
        else{
            if((bitInA | bitInB) == 0) ans += 1;
        }
        a = a>>1;
        b = b>>1;
        c = c>>1;
    }
    return ans;
}
int main()
{
    return 0;
}
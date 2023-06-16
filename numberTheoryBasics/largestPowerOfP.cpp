//https://practice.geeksforgeeks.org/problems/largest-power-of-prime4416/1
/*
    Given an integer 'n' and a prime number p. 
    Find the largest value of x, s.t. p^x divides n perfectly
*/
#include<iostream>
using namespace std;
int largestPowerOfPrime(int n , int p) {
    // let the required largest power be x 
    //x = n/p + n/p2 + n/p3 + ... 
    int x = 0;
    while(n>0){
        n = n/p; 
        x += n;
    }
    return x; 
}
int main()
{
    return 0;
}
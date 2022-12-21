/*  Eulerphi Function 
    Eulerphi(n) = means the number of numbers which are relatively coprime with n

    Eulerphi(n):
        => if n == prime number,,, then ans = n-1
            eg. for n = 13, means there are 12 numbers between 1 and 13, which are coprime with 13.
        => if n == non prime:
                //prime factors of 22 = 2,11
                EulerPhi(22) = EulerPhi(2) * EulerPhi(11) [broked into case 1]
                             = 1*10
                             = 10   
        => 

*/
#include<iostream>
using namespace std;
int main()
{   
    int a,b;
    cin>>a>>b; 
    cout<<"GCD = "<<gcd(a,b)<<endl;
    return 0;
}
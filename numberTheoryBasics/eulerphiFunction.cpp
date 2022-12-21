/*  Eulerphi Function 
    
    //Trick

    Eulerphi(n) = means the number of numbers which are relatively coprime with n

    Eulerphi(n):
        => if n == prime number,,, then ans = n-1
            eg. for n = 13, means there are 12 numbers between 1 and 13, which are coprime with 13.
        => if n == non prime:
                //prime factors of 22 = 2,11
                EulerPhi(22) = EulerPhi(2) * EulerPhi(11) [broked into case 1]
                             = 1*10
                             = 10   
        => //EulerPhi(24)  =>  //if the prime factors has power -> different type
            factorization of 24 = 2^3 * 3
            E(2^3) = p^n - p^(n-1); p = prime factor, n = power
            E(2^3) = 2^3 - 2^2 = 8-4 = 4
            eulerphi(24) = E(2^3) * E(3)
                         = 4 * 2 = 8

eg. EulerPhi(72)
72 = 2^3 * 3^2
eulerPhi(72) = E(2^3) * E(3^2)
             = (2^3 - 2^2) *  (3^2 - 3^1)
             = (8-4) * (9 - 3)
             = 4 * 6
             = 24 (ans)

*/
#include<iostream>
using namespace std;
int gcd(int a, int b){
    //rec case
    if(a == 0)  return b;

    //rec cae
    return gcd(b%a, a);
}
int eulerPhi(int n){
    int cnt = 0;
    for(int i = 1; i<n; i++){
        if(gcd(i,n) == 1){
            cnt++;
        }
    }
    return cnt;
}
int main()
{   
    int n;
    cin>>n;
    cout<<eulerPhi(n)<<endl;
    return 0;
}
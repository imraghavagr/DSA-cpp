#include<iostream>
using namespace std;
bool checkPrime(int n){
    for(int i = 2; i<n/2; i++){
        if(n%i == 0)    return false;
    }
    return true;
}
int findNearestPrime(int n){
    int leftPrime = -1, rightPrime = -1; 
    int temp = n-1; 
    while(temp >= 2){
        if(checkPrime(temp)){
            leftPrime = temp;
            break;
        }
        temp -= 1;
    }
    temp = n + 1;
    while(true){
        if(checkPrime(temp)){
            rightPrime = temp;
            break;
        }
        temp += 1;
    }
    
    if(abs(leftPrime-n) == abs(rightPrime-n))   return min(leftPrime, rightPrime);
    else if(abs(leftPrime-n) > abs(rightPrime-n))   return rightPrime;
    else    return leftPrime;

}
int main()
{   
    int n; 
    cin>>n;
    //find the left prime and the right prime     
    cout<<findNearestPrime(n)<<endl;
    return 0;
}
/*
450 -> 
1 -> 20 -> 400 
 
*/
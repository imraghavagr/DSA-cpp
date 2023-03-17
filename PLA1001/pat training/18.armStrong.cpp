#include<iostream>
#include<math.h>
using namespace std;
bool isArmStrong(int n){
    int temp = n;
    int len = 0;
    while(temp > 0){
        temp /= 10;
        len++;
    }
    temp = n;
    int sum = 0;
    while(temp > 0){
        int ld = temp%10;
        sum += pow(ld, len);
        temp /= 10;
    }
    return sum == n;
}
int main()
{   

    for(int i = 10000; i<= 99999; i++){
        if(isArmStrong(i)){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}
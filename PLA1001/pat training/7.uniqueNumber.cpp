//find the count of numbers in between [low,high] that contains unique digits
#include<iostream>
#include<unordered_map>
using namespace std;
bool uniqueDigits(int num){
    unordered_map<int,int> mp;
    int len = 0;
    while(num > 0){
        int d = num%10;
        mp[d]++;
        num /= 10;
        len++;
    }
    return mp.size() == len;
}
int main()
{      
    int m, n; 
    cin>>m>>n; 
    int cnt = 0;
    for(int i = m; i<=n; i++){

        if(uniqueDigits(i)) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
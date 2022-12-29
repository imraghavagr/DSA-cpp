#include<iostream>
using namespace std;
bool check(int n){
    int temp  = n;
    int reverse = 0;
    while(temp>0){
        reverse = reverse << 1;
        if(temp&1){
            reverse = reverse^1;
        }
        temp = temp>>1;
    }  
    cout<<reverse<<endl;
    return reverse == n; 
}
int main()
{   
    int n;
    cin>>n;
    
    if(check(n))    cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;

    return 0;
}
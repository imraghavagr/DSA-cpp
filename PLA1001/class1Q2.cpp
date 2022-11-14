#include<iostream>
using namespace std;
int solution1(int n){
    if(n == 0){
        return 0;
    }

    if(n%9 == 0){
        return 9;
    }
    else{
        //means n is 9x + k.. k will be the answer here
        return n%9;
    }
}
int solution2(int n){
    
}
int main()
{   
    int n;
    cin>>n;
    cout<<solution(n)<<endl;
    return 0;
}
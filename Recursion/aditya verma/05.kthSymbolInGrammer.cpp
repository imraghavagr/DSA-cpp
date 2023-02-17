//https://leetcode.com/problems/k-th-symbol-in-grammar/
#include<iostream>
using namespace std;

int kthGrammar(int n, int k) {
    //base case
    if(n == 1 && k == 1){
        //1st row starts with 0 
        return 0;
    }

    //hypothesis - solve for smaller input 
    int mid = (pow(2,n-1))/2;
    if(k<=mid){
        //value at nth row is exact same as n-1 th row when k<=mid
        return kthGrammar(n-1, k);
    }
    else{
        return !(kthGrammar(n-1, k-mid));
    }
}
int main()
{   
    int n,k;
    cin>>n>>k;
    cout<<kthGrammar(n,k)<<endl;
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v = {35, 15, 45, 25, 55};
    int cnt = 0; 

    for(int i = 1; i<v.size()-1; i++){
        //for current i, check on both the sides 
        if(v[i]< v[i-1] && v[i] < v[i+1])   cnt++;
    }
    cout<<cnt<<endl;
    
    return 0;
}
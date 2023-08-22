#include<iostream>
using namespace std;

int main(){

    int marks[100];
    int n;
    cin>>n;
    for(int i =0; i<n; i++){
        cin>>marks[i];
        //update
        marks[i] = marks[i]*2;
    }

    //output
    for(int i =0; i<n; i++){
        cout<<marks[i]<<" ";
    }
    cout<<endl;

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
void insertAtCorrectPosition(vector<int>&v, int val){
    //base case
    if(v.size() == 0 || v[v.size()-1]<=val){
        v.push_back(val);
        return;
    }
    //hypothesis - work for smaller input 
    int temp = v[v.size()-1];
    v.pop_back();
    insertAtCorrectPosition(v, val);

    //induction
    v.push_back(temp);
}
void mySort(vector<int> & v){
    //base case 
    if(v.size() == 1)   return;

    //hypothesis - work for smaller input 
    int val = v[v.size()-1];
    v.pop_back();
    mySort(v);

    //induction step - insert val at the correct place in smaller input array 
    insertAtCorrectPosition(v,val);
}
int main()
{   
    vector<int> v = {3,5,7,1,0,8,10};
    for(int x : v)  cout<<x<<" ";
    cout<<endl;
    mySort(v);
    for(int x : v)  cout<<x<<" ";
    cout<<endl;
    return 0;
}
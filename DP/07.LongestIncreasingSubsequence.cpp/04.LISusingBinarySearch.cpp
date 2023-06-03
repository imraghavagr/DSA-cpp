#include<iostream>
using namespace std;
int longestSubsequence(int n, int a[])
{
    vector<int> temp;
    temp.push_back(a[0]);
    for(int i = 1; i<n; i++){
        if(a[i] > temp.back())  temp.push_back(a[i]);
        else{
            //lower_bound returns the ADDRESS of the element >= key 
            //so we substract the returned value with temp.begin() to get the index 
            int index = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            temp[index] = a[i];
        }
    }
    //note- temp does not store the actual LIS 
    return temp.size();
}
int main()
{
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//gcd of all the elements of an array is equal to the gcd(a,b)
//where a = max element in the array and b = min element in the array 
//using stl 
int findGCD(vector<int> &it){
    return gcd(*max_element(it.begin(),it.end()),*min_element(it.begin(),it.end()));
}
int main()
{   
    vector<int> nums = {6,6,6,6,6};
    cout<<findGCD(nums)<<endl;
    return 0;
}
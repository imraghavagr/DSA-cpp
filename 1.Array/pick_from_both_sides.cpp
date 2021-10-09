#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

//https://www.interviewbit.com/problems/pick-from-both-sides/

using namespace std;
int main()
{
    vector<int> a{5,-2,3,1,2};
    int b;
    cin>>b;
    
    //computing prefix sum array
    vector<int> p;
    p.push_back(a[0]);
    for(int i =1; i<a.size(); i++){
        p.push_back(a[i]+p[i-1]);
    }

    //computing suffix sum array
    vector<int> s;
    s.push_back(a[a.size()-1]);
    int j =0;
    for(int i = a.size()-2; i>=0; i--){
        s.push_back(a[i]+s[j++]);
    }

    //cs1 stores the sum of first b elements
    int cs1 = p[b-1];
    //stores the sum of last b elements
    int cs2 = s[b-1];
    int ms = INT_MIN;
    
    ms = max(ms,cs1);
    ms = max(ms,cs2);
    
    int i;
    //int j; j is already declared above in this scope
    //picking up in combinations like - for b = 3, taking 1 from left and 2 from right, then 2 from left and 1 from right
    for(i =0,j = b-2;i<=b-2,j>=0 ;i++,j-- ){
        cs1 = 0;
        cs1 += p[i] + s[j];
        ms = max(ms,cs1);
    }
    cout<<ms<<endl;
    
}
//https://www.spoj.com/problems/BALIFE/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solution(vector<int> &v, int n){
    long long sum = 0;
    for(int i = 0; i<n; i++){
        sum += v[i];
    }
    
    if(sum % n != 0)    return -1;

    int individualTargetLoad = sum/n;
    int ans = INT_MIN;

    vector<int> csum(n);
    csum[0] = v[0];
    for(int i = 1; i<n; i++){
        csum[i] = csum[i-1]+v[i];
    }

    for(int i = 0; i<n; i++){
        int loadRequired = individualTargetLoad*(i+1);
        ans = max(ans, abs(loadRequired - csum[i]));
    }
    return ans;
}

int main()
{   
    int n;
    cin>>n;
    vector<int> v;
    while(n != -1){
        int x;
        for(int i = 0; i<n; i++){
            cin>>x;
            v.push_back(x);
        }
        cout<<solution(v,n)<<endl;
        v.clear();
        cin>>n;
    }
    return 0;
}
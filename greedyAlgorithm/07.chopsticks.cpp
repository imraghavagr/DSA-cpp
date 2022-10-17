//https://www.codechef.com/problems/TACHSTCK
#include<iostream>
#include<vector>
using namespace std;
int solution(int n, int d, vector<int> &v){
    if(n == 1)return 0;
    
    sort(v.begin(), v.end());
    
    int ans = 0, i = 0, j = 1;
    while(j<n){
        if(v[j]-v[i] <= d){
            i+=2;
            j+=2;
            ans++;
        }
        else{
            i++;
            j++;
        }        
    }
    return ans;
}
int main()
{   
    int n,d;
    cin>>n>>d;
    vector<int> lenVec(n,0);
    int x;
    for(int i = 0; i<n; i++){
        cin>>x;
        lenVec[i] = x;
    }
    cout<<solution(n,d,lenVec)<<endl;
    return 0;
}
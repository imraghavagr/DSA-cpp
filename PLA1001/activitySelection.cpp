//busyman 
//Also known as activity selection problem 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int solution(vector<pair<int,int>> &v){
    
    int ans = 1;
    int prev = 0;
    int i = 1;
    cout<<0<<" ";
    while(i<v.size()){
        if(v[i].first >= v[prev].second){
            prev = i;
            ans++;
            cout<<i<<" ";
        }
        i++;
    }
    cout<<endl;
    return ans;
}
int main()
{
    int t;
    cin>>t;
    vector<pair<int,int>> v;
    while(t--){
        int n;
        cin>>n;
        //take input n pairs 
        for(int i = 0; i<n; i++){
            int a,b;
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        //sort the vector v now
        sort(v.begin(), v.end(), compare);
        
        //call the solve function now
        cout<<"Order of activities is : ";
        int ans = solution(v);
        cout<<"Total number of activities performed: "<<ans<<endl;
        
        //clear the vector before taking the next input
        v.clear();
    }
    return 0;

}
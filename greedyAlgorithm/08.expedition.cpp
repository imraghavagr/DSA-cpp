#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> a, pair<int, int> b){
    return a.second>b.second;
}
int solution(vector<pair<int,int>> &v, int l, int fuelLeft){
    //sort the vector in descending order according to the fuel capacity in each stop
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i<v.size(); i++){
        v[i].first = l-v[i].first;
    }

    int fuelRequired = l;
    int stops = 0;
    int lastStop = 0;
    if(fuelLeft>=fuelRequired)return stops;
    for(int i = 0; i<v.size(); i++){
        if(fuelLeft >= (v[i].first-lastStop)){
            //we can reach the ith stop and fill the tank here 
            
            //subtract the fuel leaked while travelling to this stop
            fuelLeft -= (v[i].first-lastStop);
            //fill the fuel 
            fuelLeft += v[i].second;
            //update the fuelRequired 
            fuelRequired -= (v[i].first - lastStop);
            //update the lastStop 
            lastStop = v[i].first;
            //increase the stop count
            stops++;
        }
        if(fuelLeft>=fuelRequired){
            return stops;
        }
    }
    return -1;    
}
int main()
{
    int t;
    cin>>t;
    int n;
    int x,y,l,p;
    vector<pair<int,int>> v;
    while(t--){
        cin>>n;
        for(int i = 0; i<n; i++){
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }
        cin>>l>>p;
        cout<<solution(v,l,p)<<endl;
        v.clear();
    }
    return 0;
}
//https://www.spoj.com/problems/BAISED/#:~:text=BAISED%20%2D%20Biased%20Standings&text=During%20the%20registration%20each%20team,would%20please%20all%20of%20you.

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


//Normal sorting solution 
// long long solution(vector<int> &v){
//     sort(v.begin(),v.end());
//     long long ans = 0;
//     for(int i = 0; i<v.size(); i++){
//         // cout<<v[i]<<" ";
//         ans += abs(v[i] - (i+1));
//     }
//     // cout<<endl;
//     return ans;
// }

//counting sort approach - O(N)
long long solution (vector<int> &v){
    
    int arr[10000000] = {0};
    for(int i = 0; i<v.size(); i++){
        arr[v[i]]++;
    }
    int availableRank = 1;
    long long ans = 0;
    for(int i = 1; i<=v.size(); i++){
        while(arr[i] > 0){
            ans += abs(i - availableRank);
            availableRank++;
            arr[i]--;
        }
    }
    return ans;    
}

int main(){
    int t;
    cin>>t;    
    int n;
    string s;
    int pos;
    vector<int> v;
    while(t--){
        cin>>n;
        for(int i = 0; i<n; i++){
            cin>>s;
            cin>>pos;
            v.push_back(pos);
        }
        //solve for v
        cout<<solution(v)<<endl;
        //clear vector v before again taking input
        v.clear();
    }
    return 0;
}
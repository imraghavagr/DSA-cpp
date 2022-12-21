#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> solve(int n){
    vector<int> ans;
    int arr[1001] = {0};
    queue<int> q;

    //first fill up the cards from 1 to n in the queue
    for(int i = 1; i<=n; i++){
        q.push(i);
    }
    int i = 1;
    while(!q.empty()){
        //now give i number of rotations in the queue
        int j = 0;
        while(j<i){
            int f = q.front();
            q.pop();
            q.push(f);
            j++;
        }
        int f = q.front();
        if(arr[f] != 0){
            ans.push_back(-1);
            return ans;
        }
        arr[f] = i;
        q.pop();
        i++;
    }
    for(int i = 0; i<1000; i++){
        if(arr[i]){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main()
{   
    int t;
    cin>>t;
    int n;
    vector<int> ans;
    while(t--){
        cin>>n; 
        ans = solve(n);
        for(int x : ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
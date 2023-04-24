#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int solve(vector<vector<int>> &v){
    int cnt = 0;
    int ansRowIndex;
    int maxFullSpaces = 0;
    for(int i = 0; i<v.size(); i++){
        cnt = 0;
        for(int j = 0; j<v[0].size(); j++){
            if(v[i][j]) cnt++;
        }
        if(maxFullSpaces < cnt){
            maxFullSpaces = cnt;
            ansRowIndex = i;
        }
    }
    return ansRowIndex;
}
int main()
{   
    vector<vector<int>> v;
    int r,c,x;
    cin>>r>>c;
    for(int i = 0; i<r; i++){
        vector<int> temp;
        for(int j = 0; j<c; j++){
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    //0 - empty
    //1 - full 
    cout<<solve(v)<<endl;
    return 0;
}
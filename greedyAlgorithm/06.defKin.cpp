#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solution(int w, int h, vector<int> &rowP, vector<int> & colP, int n){
    if(n == 0){
        //all cells are in danger 
        return w*h;
    }
    
    sort(colP.begin(), colP.end());
    sort(rowP.begin(), rowP.end());

    //corner case
    int maxRecLength = colP[0]-1;
    int maxRecHeight = rowP[0]-1;
    
    for(int i = 1; i<colP.size(); i++){
        maxRecLength = max(maxRecLength,colP[i]-colP[i-1]-1);
        maxRecHeight = max(maxRecHeight,rowP[i]-rowP[i-1]-1);
    }
    //corner case - from last row present tower to the last row in the board and same for col too 
    maxRecLength = max(maxRecLength, w-colP[colP.size()-1]);
    maxRecHeight = max(maxRecHeight, h-rowP[rowP.size()-1]);
    
    return maxRecLength*maxRecHeight;
}
int main()
{   
    int t;
    cin>>t;
    int w,h,n;
    vector<int> rowPositions,colPositions;
    int x,y;
    while(t--){
        cin>>w>>h>>n;
        for(int i = 0; i<n; i++){
            cin>>x>>y;
            colPositions.push_back(x);
            rowPositions.push_back(y);
        }
        //solve for this grid 
        cout<<solution(w,h,rowPositions,colPositions,n)<<endl;
        colPositions.clear();
        rowPositions.clear();
    }
    return 0;
}
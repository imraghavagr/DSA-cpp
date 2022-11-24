#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isPossible(int mid,vector<int>&seats,vector<pair<int,int>> &arr){
    //check if it is possible to place alex in such a way that 
    //the minimum distance between him and the other person is mid units.
    for(int i = 0; i<arr.size();i++){
        //if at any index if both first and second value of any pair are >= mid, then return true
        if((arr[i].first >= mid || arr[i].first == -1) && (arr[i].second >= mid || arr[i].second == -1)){
            return true;
        }
    }
    return false;    
}
int maxDistToClosest(vector<int>& seats) {
    vector<pair<int,int>> arr;
    int lastLeftOneIndex = -1;
    int cntZeroes = 0;
    for(int i = 0; i<seats.size(); i++){
        if(seats[i] == 1){
            lastLeftOneIndex = i;
        }
        else{
            if(lastLeftOneIndex == -1){
                //this means there is no 1 in the left of this zero
                arr.push_back(make_pair(-1,-1));
            }
            else{
                arr.push_back(make_pair(i-lastLeftOneIndex,-1));
            }            
            cntZeroes++;
        }
    }

    int lastRightOneIndex = -1;
    for(int i = seats.size()-1; i>=0 ;i--){
        if(seats[i] == 1){
            lastRightOneIndex = i;
        }
        else{
            if(lastRightOneIndex == -1){
                //means there is no 1 in the right of this zero
                arr[cntZeroes-1].second = -1;
            }
            else{
                arr[cntZeroes-1].second = lastRightOneIndex - i;
            }            
            cntZeroes--;
        }
    }
    //the minimum possible distance between him and the closest person
    int s = 1;
    //the maximum possible will be, if one person sits in the first see and he sits on the last seat.
    int e = seats.size()-1;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(isPossible(mid,seats,arr)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}
int main()
{   
    vector<int> v = {0,1};
    cout<<maxDistToClosest(v)<<endl;
    return 0;
}
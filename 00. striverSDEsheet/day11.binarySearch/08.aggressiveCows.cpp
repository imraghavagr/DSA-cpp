#include<iostream>
using namespace std;
bool isPossible(vector<int> &stalls, int numCows, int seperation){
    //we will try to place cows in the required speration 
    int cowsPlaced = 1; 
    int lastCowPlacedAt = 0; 
    //next cow can be placed at stalls[lastCowPlacedAt] + seperation
    int i = 1; 
    while(i<stalls.size() && cowsPlaced<numCows){
        if(stalls[i] >= stalls[lastCowPlacedAt]+seperation){
            //place a cow here 
            cowsPlaced++;
            lastCowPlacedAt = i; 
        }
        i++;
    }
    return cowsPlaced == numCows; 
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0, e = stalls.back()-stalls.front();
    int ans = -1; 

    while(s<=e){
        int mid = s + (e-s)/2; 

        if(isPossible(stalls, k, mid)){
            ans = mid; 
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    return 0;
}
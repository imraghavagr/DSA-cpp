#include<iostream>
using namespace std;
bool canPlace(int minSeperationReq, vector<int> &stalls, int n, int numCows){
    int numCowsPlaced = 1; 
    int lastPlaceIndex = 0; 
    //now try to place remaining cows with a min separation of minSepeartionReq 
    int i = 1; 
    while(i < n && numCowsPlaced < numCows){
        if(stalls[i] - stalls[lastPlaceIndex] >= minSeperationReq){
            //place a cow here 
            lastPlaceIndex = i; 
            numCowsPlaced += 1; 
        }
        i++;
    }
    return numCowsPlaced == numCows;  
}
int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(), stalls.end());
    
    int start = 1;
    int end = stalls.back() - stalls.front();
    int ans = -1; 
    while(start <= end){
        int mid = start + (end-start)/2; 
        if(canPlace(mid, stalls, n, k)){
            ans = mid; 
            //try to maximize the answer 
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans; 
}
int main()
{
    return 0;
}
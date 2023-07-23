#include<iostream>
using namespace std;
bool isPossible(int k, vector<int> &piles, int h){
    long long hrReq = 0; 
    for(int num : piles){
        hrReq += num / k;
        if(num % k != 0)    hrReq += 1; 
        if(hrReq > h)   return false;
    }
    return true;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int s = 1; 
    int e = *max_element(piles.begin(), piles.end());
    int ans; 
    while(s<=e){
        int mid = s + (e-s)/2; 
        if(isPossible(mid, piles, h)){
            ans = mid; 
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{
    return 0;
}
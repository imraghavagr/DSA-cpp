#include<iostream>
using namespace std;
bool isPossible(int maxWeightAllowed,vector<int> weights, int days){
    int currWeight = 0;
    int d = 1;
    for(int i = 0; i<weights.size(); i++){
        if(currWeight + weights[i] <= maxWeightAllowed){
            currWeight += weights[i];
        }
        else{
            if(weights[i] > maxWeightAllowed)   return false;
            currWeight = weights[i];
            d++;
            if(d>days)  return false;
        }
    }
    return true;
}
int shipWithinDays(vector<int>& weights, int days) {
    int s = *min_element(weights.begin(), weights.end());
    int e = 0; 
    for(int wt : weights)   e += wt;
    int ans = 0; 
    while(s<=e){
        int mid = s + (e-s)/2; 
        if(isPossible(mid, weights, days)){
            ans = mid; 
            e = mid - 1;
        }
        else    s = mid + 1;
    }
    return ans;
}
int main()
{
    return 0;
}
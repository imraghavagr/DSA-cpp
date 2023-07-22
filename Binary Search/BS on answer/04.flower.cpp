#include<iostream>
using namespace std;
bool isPossible(vector<int> &v, int days, int m, int k){
    //we need to find k consecutive bloomed flowers m times 
    //in the array        
    int cnt = 0, numBouq = 0;
    for(int i = 0; i<v.size(); i++){
        if(v[i] <= days){
            cnt++;
        }
        else{
            numBouq += cnt / k;
            cnt = 0;
        }
        if(numBouq >= m)    return true;
    }
    numBouq += cnt/k;
    return numBouq >= m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if((long long)m*k > n) return -1; 
    int s = 1;
    int e = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1; 
    while(s<=e){
        int mid = s + (e-s)/2; 
        if(isPossible(bloomDay, mid, m, k)){
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
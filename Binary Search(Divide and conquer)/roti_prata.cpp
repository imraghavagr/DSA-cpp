//https://www.spoj.com/problems/PRATA/
#include<iostream>
#include<algorithm>
using namespace std;
bool isPossible(int *arr,int p, int n,int maxTime){
    int roti_made = 0;
    int curr_chef = 0;
    int time_taken = 0;
    for(int i = 1; i<=p; i++){
        if(time_taken + (arr[curr_chef]*i) <= maxTime){
            roti_made++;
            time_taken += arr[curr_chef]*i;
            if(roti_made == p){return true; }
        }
        else{
            curr_chef++;
            if(curr_chef > n-1){return false; }
            time_taken = 0;
            i = 0;
        }
    }
    //return true; not required
}
int main(){

    int t;
    cin>>t;
    int p;
    int l;
    int arr[50];
    while(t--){
        cin>>p>>l;
        for(int i = 0; i<l; i++) cin>>arr[i];
        sort(arr,arr+l);
        //end will be the time taken by worst rank chef to cook all p parathas
        int sum = 0;
        int r = arr[l-1];
        for(int i = 1; i<=p; i++){
            sum += (i*r);
        }
        int s = 0;
        int e = sum;
        int ans = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossible(arr,p,l,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
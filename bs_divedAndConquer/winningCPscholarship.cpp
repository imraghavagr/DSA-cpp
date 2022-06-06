#include<iostream>
using namespace std;

bool isPossible(int n, int mid, int m, int x, int y){
    // total req coupons to give 100% scholarship to mid number of students
    long long req = mid*x;
    //total availabe coupons 
    long long available = m + (n-mid)*y;
    return req <= available;
}
int main(){

    long n,m,x,y;
    cin>>n>>m>>x>>y;
    long s = 0;
    long e = n;
    long ans = 0;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(isPossible(n,mid,m,x,y)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include<iostream>
#include<math.h>
using namespace std;
double mutliply(double number, int n){
    double ans = 1.0;
    for(int i = 1; i<=n; i++){
        ans = ans * number;
    }
    return ans;
}
double fastMultiply(double number, int n){
    double ans = 1.0;
    while(n>0){
        if(n&1){
            //odd
            ans *= number;
            n -= 1;
        }
        else{
            number = number*number;
            n = n/2;
        }
    }
    return ans;
}
double getNthRoot(int n, int m){
    double low = 1;
    // double high = m/n; we can also reduce the search space by doing this
    double high = m;
    //epsilon - difference.. keep 1 more than the number of places we want our ans
    double eps = 1e-6;

    while((high - low) > eps){
        double mid = low + (high-low)/2;
        if(fastMultiply(mid, n) < m){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    cout<<low<<" "<<high<<endl;
    //jus to check 
    cout<<pow(m, (double)(1.0/(double)n))<<endl;
    
    //we can also return high
    return low;
}
int main()
{   
    int n,m;
    cin>>n>>m;
    cout<<getNthRoot(n,m)<<endl;
    return 0;
}
#include<iostream>
using namespace std;

/*
lower_bound -> smallest value greater than or euqal to target
upper_bound -> smallest value greater than the target 
floor -> greatest value smaller than or equal to target
ceil  -> smallest value greater than or euqal to target

if key is not present, than both lower_bound and upper_bound will give us the same results 

NOTE: 
lower_bound and ceil are same, but upper_bound and floor are not same 
*/
int floorInSortedArray(vector<long long> &v, long long x){
    int s = 0, e = v.size()-1;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(v[mid] == x) return mid; 
        else if(x > v[mid]){
            s = mid + 1;
            ans = mid; 
        }
        else{
            e = mid - 1; 
        }
    }
    return ans;
}
int floorInSortedArray(vector<long long> &v, long long x){
    int s = 0, e = v.size()-1;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(v[mid] == x) return mid; 
        else if(x > v[mid]){
            s = mid + 1;
        }
        else{
            e = mid - 1;
            ans = mid;  
        }
    }
    return ans;
}
int main()
{
    return 0;
}
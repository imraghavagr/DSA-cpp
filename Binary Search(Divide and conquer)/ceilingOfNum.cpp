#include<iostream>
#include<vector>
using namespace std;
/*Given a sorted array and a target, find ceiling of that target number
ceiling = smallest element in array, greater than or equal to the target element
eg- 
Arr = [2,3,5,3,14,16,18]
target = t
ceiling(t = 15) = 16
ceiling(t = 14) = 14
celing(t = 4) = 5
*/
int ceiling(vector<int> v, int t){
    int s = 0;
    int e = v.size()-1;
    while(s<=e){
        
        int mid = s + (e-s)/2; // usually we write mid = (s+e)/2 , but this s+e can sometimes exceed integer limits therefore using alternative representation of the same formula
        
        if(t == v[mid] ){
            return mid;
        }
        
        else if(t > v[mid]){
            s = mid+1;
        }
        else{
            e = mid -1;
        }
    }
    return s; // for floor of number i.e. greatest number smaller than or equal to target. return end
}
int main(){

    vector<int> v {2,3,5,3,14,16,18};
    int t = 16;
    cout<<v[ceiling(v,t)]<<endl;
  

    return 0;
}
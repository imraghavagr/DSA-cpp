#include<iostream>
#include<vector>
using namespace std;
int findPeak(vector<int> &mountainArr){
        int s = 0;
        int e = mountainArr.size()-1;
        int mid;
        while(s<e){
            mid = s + (e-s)/2;
            if(mountainArr[mid] >mountainArr[mid+1]){
                //desc array
                e = mid;
            }
            else if(mountainArr[mid] < mountainArr[mid+1]){
                //asc array
                s = mid+1;
            }
        }
        return s;
}
int binarySearch(int target,int s,int e, vector<int> &mountainArr, bool inAsc){
        // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11 
           
        int mid;
        //bool inAsc = mountainArr.get(s)<mountainArr.get(e);
        while(s<=e){
            mid = s + (e-s)/2;
            if(mountainArr[mid] == target){
                return mid;
            }
            if(inAsc){
                if(target <mountainArr[mid]){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }
            else{
                if(target<mountainArr[mid]){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
        }
        return -1;
}
int soln(vector<int> &arr,int target){
    //find the peak of the array
    int peak = findPeak(arr);
    cout<<peak<<endl;
    //search in first part
    int ans = binarySearch(target,0,peak,arr,true);
    if(ans!=-1){
        return ans;
    }
    else{
        ans = binarySearch(target,peak+1,arr.size()-1, arr,false);
        return ans;
    }
}
int main(){

    vector<int> arr{  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11 };
    int target = 12;
    cout<<soln(arr,target)<<endl;
    return 0;
}
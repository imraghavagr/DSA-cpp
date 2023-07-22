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
int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
	int s = 0, e = n-1; 
	while(s<=e){
		int mid = s + (e-s)/2; 
		if(arr[mid] == x)	return mid+1;
		if(x > arr[mid]){
			s = mid + 1;
		}
		else	e = mid - 1;
	}
	return s;
}
int lowerBound(vector<int> arr, int n, int x) {
	int s= 0, e = n-1; 
	int ans = n;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(arr[mid] == x) return mid;
		if(x < arr[mid]){
			ans = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}
	return ans;
}
void inbuiltFunctions(vector<int> &arr, int x){
    cout<<lower_bound(arr.begin(), arr.end())-arr.begin();
    cout<<upper_bound(arr.begin(), arr.end())-arr.begin();
}
int main()
{
    return 0;
}
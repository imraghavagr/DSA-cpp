#include<iostream>
#include<algorithm>
using namespace std;

bool canDistrBooks(int *arr, long long curr_min, int m, int n){
	int studentUsed = 1;
	int pages_reading = 0;
	for(int i = 0; i<n; i++){
		if(pages_reading + arr[i] > curr_min){
			studentUsed++;
			pages_reading = arr[i];
			if(studentUsed > m){
				return false;
			}
		}
		else{
			pages_reading += arr[i];
		}
	}
	return true;
	

}
int main(){
	
	int arr[] = {162,503, 755, 914, 1130, 1219, 1266, 1646, 1928, 2223, 2225, 2313, 2373, 2552, 2564, 2783, 2820, 2895, 2943, 3187, 3242, 3299, 3310, 3429, 3467, 3837, 4089, 4296, 4507, 4751, 4928, 5165, 5481, 5490, 5835, 6255, 6322, 6412 ,6608, 6816, 6820, 6847, 6851, 6931, 6933, 7729, 7856, 7999, 8022, 8141, 8227, 8235, 8321, 8358, 8411, 8652, 8753, 8820, 9237, 9526};
	int n = sizeof(arr)/sizeof(int);
	int m = 31;

    int s = arr[n-1];
	long long sum = 0;
	for(int i = 0; i<n; i++){
		sum += arr[i];
	}
	cout<<sum<<endl;
	int e = sum;
	int ans = 0;
	while(s<=e){
		long long mid = s  + (e-s)/2;
		if(canDistrBooks(arr,mid,m,n)){
			ans = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	cout<<ans<<endl;
    return 0;
}
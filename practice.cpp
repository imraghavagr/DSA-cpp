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
	int t;
	cin>>t;
	int arr[100];
	int n;
	int m;
	while(t--){
		int n;
		cin>>n>>m;
		for(int i = 0; i<n; i++) cin>>arr[i];
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
	}
	

	return 0;
}
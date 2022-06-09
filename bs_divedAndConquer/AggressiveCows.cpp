#include<iostream>
#include<algorithm>
using namespace std;

bool canPlaceCow(int *a, int dist, int c, int n){
	int cowPlaced = 1; // 1st cow placed at 1st stall
	int i = 0, j = 1; //i is the idx, where last cow is placed. j is a potential stall for placing next cow
	while(j<n and cowPlaced <c){
		if(a[j] - a[i] >= dist){
			cowPlaced++;
			i = j;
			j++;
		}
		else{
			j++;
		}
	}
	return cowPlaced == c;
}
//another implementation 
// bool canPlaceCow(int mid, int*stalls, int n, int c){
// 	int cowPlaced = 1;
// 	int pos = 0;
	
// 	for(int i =pos+1; i<n; i++){
// 		if(stalls[pos]+mid<=stalls[i]){
// 			pos = i;
// 			cowPlaced++;
// 			if(cowPlaced==c){
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }
int main(){
	int t;
	cin>>t;
	int arr[100000];
	int n;
	int c;
	while(t--){
		int n;
		cin>>n>>c;
		for(int i = 0; i<n; i++) cin>>arr[i];
		sort(arr,arr+n);
		int s = 0;
		int e = arr[n-1] - arr[0]; //end will be the max possible separation is one cow is placed at begin and second at the end.
		int ans = -1;
		while(s<=e){
			int mid = s  + (e-s)/2;
			if(canPlaceCow(arr,mid,c,n)){
				ans = mid;
				s = mid + 1;

			}
			else{
				e = mid-1;
			}
		}
		cout<<ans<<endl;
	}
	

	return 0;
}
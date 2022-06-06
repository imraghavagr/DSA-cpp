#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

bool isPossible(int arr[],int n,int m,int curr_min){

	int studentUsed = 1; 
	int pages_reading = 0;
	for(int i =0; i<n; i++){
		if((pages_reading + arr[i]) > curr_min){
			studentUsed++;
			pages_reading = arr[i];
			if(studentUsed>m){
				return false;
			}
			else{
				pages_reading+= arr[i];
			}
		}
	} 
	return true;

}

int findPages(int arr[], int n, int m, int end){
	
	int ans = INT_MAX;

	if(n<m){
		return -1;
	}

	//count the no. of pages

	int s = arr[n-1];
	int e = end;

	while(s<=e){
		int mid = (s+e)/2;
		if(isPossible(arr,n,m,mid)){
			ans = min(mid,ans);
			e = mid - 1;
		}
		else{
			//it is not possible to divide at x pages
			//increase the number of pages
			s = mid + 1;
		}
	}
	return ans;

}

int main(){

	int t;
	cin>>t;
	int arr[1000];
	while(t>0){
		int n,m;
		cin>>n>>m;
		int sum = 0;
		for(int i =0; i<n; i++){
			cin>>arr[i];
			sum += arr[i];
		}

		cout<<findPages(arr,n,m,sum)<<endl;

		t--;
	}
	
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
bool canPlaceCow(int mid, int*stalls, int n, int c){
	int cowPlaced = 1;
	int pos = 0;
	
	for(int i =pos+1; i<n; i++){
		if(stalls[pos]+mid<=stalls[i]){
			pos = i;
			cowPlaced++;
			if(cowPlaced==c){
				return true;
			}
		}
	}
	return false;
}
int aggressiveCows(int* stalls, int n, int c){
	sort(stalls,stalls+n);
	int s = 0;
	int e = stalls[n-1]-stalls[0];
	int ans = -1;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(canPlaceCow(mid,stalls,n,c)){
			s = mid+1;
			ans = mid;
		}
		else{
			e = mid-1;
		}
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	int n,c;
	int stalls[100001];
	while(t--){
		cin>>n>>c;
		for(int i =0; i<n; i++){
			cin>>stalls[i];
		}
		cout<<aggressiveCows(stalls,n,c)<<endl;
	}
	return 0;
}
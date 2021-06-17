#include<iostream>
#include<algorithm>
using namespace std;

bool canPlaceCow(int stalls[], int n, int c, int min_sep){

	int cnt = 1;
	int lastCowPlacedAtIdx = 0;
	for(int i =1; i<n; i++){
		if((stalls[i] - stalls[lastCowPlacedAtIdx]) >= min_sep){
			lastCowPlacedAtIdx = i;
			cnt++;
		}
		if(cnt == c){
			return true;
		}
	}

	return false;

}

int main(){

	int t;
	cin>>t;
	int n,c;
	int stalls[100000];
	while(t>0){
		//n - no. of stalls
		//c - no. of cows
		cin>>n>>c;
		for(int i =0; i<n; i++){
			cin>>stalls[i];
		}
		
		sort(stalls,stalls+n);
		
		//binary search
		//defining search space
		int s = 0;
		int e = stalls[n-1]-stalls[0];
		int ans = 0;
		while(s<=e){
			int mid = (s+e)/2;
			bool cowPaced = canPlaceCow(stalls,n,c,mid);
			if(cowPaced){
				ans = mid;
				s = mid+1;
			}
			else{
				e = mid-1;
			}
		}
		t--;
		cout<<ans<<endl;
	}



	return 0;
}

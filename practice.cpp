#include<iostream>
#include<vector>
#include<algorithm>
#define MAXSIZE 100001
using namespace std;

int N;
int A[MAXSIZE];
int ans;
void solve(){
	
	for(int i = 0; i<N; i++){
		A[i] = abs(A[i]);
	}
	sort(A,A+N);

	for(int i = 0;i <N; i++){
		if(A[i] >= 0){
			ans = A[i];
		}
		return;
	}
}
int main(){
	cin>>N;
	for(int i = 0; i<N; i++)	cin>>A[i];
	solve();
	cout<<ans<<endl;
	return 0;
}
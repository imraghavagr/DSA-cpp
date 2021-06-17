#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b){
	return a>b; //for desecending order
	//return a<b; for ascending order
}
int main(){

	int a[100];
	int n;
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}

	sort(a,a+n,compare);
	//sort(a,a+n) ascending order by default

	for(int i=0; i<n; i++){
		cout<<a[i];
	}

	return 0;
}
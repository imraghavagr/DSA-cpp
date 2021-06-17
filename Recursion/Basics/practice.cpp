#include<iostream>
using namespace std;

int fastPower(int a,int n){
	if(n == 0){
		return 1;
	}

	//rec case
	int ans = fastPower(a,n/2);
	ans*=ans;
	if(n&1){
		//odd
		return a*ans;
	}
	else{
		return ans;
	}
}
int main(){

	int a,n;
	cin>>a>>n;
	cout<<fastPower(a,n)<<endl;


	return 0;
}

#include<iostream>
using namespace std;

int power(int a, int n){
	//base case
	if(n == 0){ return 1; }

	//rec case
	return a*power(a,n-1);
}
int fastPower(int a, int n){

	//base case
	if(n == 0){
		return 1;
	}
	//rec case
	int small_ans = fastPower(a,n/2);
	small_ans*=small_ans;
	if(n&1){
		//n is odd
		return a*small_ans;
	}
	else{
		//n is even
		return small_ans;
	}


}
int main(){

	int a,n;
	cin>>a>>n;
	cout<<power(a,n)<<endl;
	cout<<fastPower(a,n)<<endl;

	return 0;
}

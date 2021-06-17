#include<iostream>
using namespace std;

//Given an integer, count the no. of set bits int its binary representation
int countSetBitsMethod1(int n){

	int x;
	int ans = 0;

	//ans will be the number of times while loop runs
	// n = n & (n-1) , this will remove the first set bit from the number from right to left every time
	while(n>0){
		if(n&1 == 1){ ans ++; }
		n = n>>1;
	}

	return ans;
}
int countSetBitsMethod2(int n){

	int ans = 0;
	while(n > 0){
		n = n & (n-1);
		ans++;
	}
	return ans;
}
int main(){

	int N;
	cin>>N;
	cout<<countSetBitsMethod1(N)<<endl;
	cout<<countSetBitsMethod2(N)<<endl;

	//method 3 - using in-built function
	cout<<__builtin_popcount(N)<<endl;

	return 0;
}

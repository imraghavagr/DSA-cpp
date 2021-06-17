#include<iostream>
using namespace std;

//Replace bits from i to j index in binary representation 
//of integer N by that of integer M.
// N and M are 32 bit numbers

int clearRangeOfBits(int n, int i, int j){

		int a  = (~0) << (j+1);
		int b = (1<<i) - 1;
		int mask = a|b;
		int ans = n&mask;
		return ans;
}

int replaceNM(int n, int m, int i, int j){
	
	int n_ = clearRangeOfBits(n, i, j);
	int mask = (m << i);
	
	return (n_ | mask);
}

int main(){
	
	int n,m;
	int i,j;
	cin>>n>>m;
	cin>>i>>j;
	cout<<replaceNM(n,m,i,j)<<endl;
	
	return 0;
}

#include<iostream>
using namespace std;

int decimal_to_binary(int n){

	int p = 1;
	int ans = 0;

	while(n>0){
		int last_bit = (n & 1);
		ans +=  (p*last_bit);
		n = n >> 1;
		p = p * 10;
	}

	return ans;
}

int main(){

	int n;
	cin>>n;

	cout<<decimal_to_binary(n)<<endl;




	return 0;
}

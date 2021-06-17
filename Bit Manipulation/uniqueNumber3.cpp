#include<iostream>
using namespace std;

//given an array of size n, where every number inside the array occurs thrice, except one number, find that unique number
int main(){
	
	int n;
	cin>>n;
	int num;
	int sum[64] = {0}; //array of fixed size if always O(1) space
	
	for(int i =0 ; i<n; i++){
		cin>>num;
		//update the sum array 
		//by extracting bits
		int j = 0;
		while(num>0){
			int last_bit = (num&1);
			sum[j] += last_bit;
			j++;
			num = (num >> 1);
		}
	}

	int p =1;
	int ans = 0;
	//iterate over the sum array and reduce everything by mod 3

	for(int i =0; i<64; i++){
		sum[i] %= 3;
		ans += (sum[i]*p);
		p = p<<1; // p*=2
	}
	cout<<ans<<endl;
	
	return 0;
}

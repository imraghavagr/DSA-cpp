#include<iostream>
using namespace std;
#define ll long long
void prime_sieve(int *p){
	//mark all multiples of 2 as non prime
	// or we can say that mark all prime numbers as potential prime
	for(ll i = 3;i<=1000000; i+=2){
		p[i] = 1;
	}

	//sieve
	for(ll i = 3; i<=1000000; i+=2){
		//check is current num is marked as prime that is 1
		if(p[i] == 1){
			//mark all multiples of i as not prime
			for(ll j = i*i; j<=1000000; j+=i){
				p[j] = 0;
			}
		}
	}

	//special cases
	p[2] = 1;
	p[1] = p[0] = 0;
}
int main(){

	int n; 
	cin>>n;
	int p[1000005] = {0};
	prime_sieve(p);
	//we have calculated all prime numbers till 10^6
	//lets check prime nums upto n
	for(int i = 0; i<=n; i++){
		if(p[i] == 1) cout<<i<<" ";
	}
	cout<<endl;
	
	return 0;
}

//int[] arr = new int[10001];
//computing prime numbers efficiently using Prime Sieve
//Prime Sieve
//Eratosthenes Sieve

#include<iostream>

using namespace std;
#define ll long long
//Sieve approach - generate an array containing prime numbers
void prime_sieve(int *p){

	//skip all even numbers
	//means marking all odd numbers as prime 
	//as odd numbers can be potential primes
	for(int i = 3; i<=1000000; i+=2){
		p[i] = 1; //marking as prime
	}

	//Sieve Code
	for(ll i = 3; i<=1000000; i+=2){

		//if the current number is not market (it is prime)
		if(p[i] == 1){ 
			for(ll j = i*i; j<=1000000; j+=i){
				p[j] = 0; //non prime
			}
		} 

	}
	//special cases
	p[0] = 0;
	p[1] = 0;
	p[2] = 1; // 2 is the only even prime number


}

int main(){

	//we have an array p of index 0 to 10^6 denoting 10^6  numbers
	//we will put value = 1 for prime and value = 0 for non-prime
	int n;
	cin>>n;

	int p[1000000] = {0};
	prime_sieve(p);
	//after this function call we will have an array of prime numbers till 10^6
	//lets print till n

	for(int i =0; i<=n; i++){
		if(p[i] == 1){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	
	return 0;
}

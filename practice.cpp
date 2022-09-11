//Ques- given an array of size n. Return the min penalty
//penalty = sum of numbers left out while making an alternate prime non prime sequence out of the given array 
//alternating prime-non prime seq -> adjacent elements alternate between prime and non-prime
//i/p = arr = [3,7,1,4,6,6]
//o/p = 1
//possible sequence = 4 3 6 7 6

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
#define ll long long 
//Sieve approach - generate an array containing prime numbers
void prime_sieve(int *p,int n){
	for(int i = 3; i<=n; i+=2){
		p[i] = 1; //marking as prime
	}
	//Sieve Code
	for(ll i = 3; i<=n; i+=2){

		//if the current number is not market (it is prime)
		if(p[i] == 1){
			//mark all multiples of p[i] as non prime
			for(ll j = i*i; j<=n; j+=i){
				p[j] = 0; //non prime
			}
		}

	}
	//special cases
	p[0] = 0;
	p[1] = 0;
	p[2] = 1; // 2 is the only even prime number
}

//m = maximum number present in the given arr
//p = max(sizOfprimes,sizeOfNprimes)
//O(mlog(logm)) + O(n) + O(pLogp) + O(p-1) = O(nloglogn)
//space - O(m)
int minPenalty(int n, int*arr){
	int maxNum = INT_MIN;
	for(int i = 0; i<n; i++){
		maxNum = max(maxNum,arr[i]);
	}
	//now find all prime numbers till maxNum using prime sieve
	int p[maxNum+1] = {0};
	prime_sieve(p,maxNum+1); 

	//now make two separate arrays of of prime and non primes present in arr
	vector<int> primes,nprimes;
	for(int i = 0; i<n; i++){
		if(p[arr[i]] == 1){
			//prime 
			primes.push_back(arr[i]);
		}
		else{
			nprimes.push_back(arr[i]);
		}
	}
	// for(int x : primes)cout<<x<<" ";
	// cout<<endl;
	// for(int x : nprimes)cout<<x<<" ";
	// cout<<endl;
	int pSize = primes.size();
	int npSize = nprimes.size();
	int penalty = 0;
	if(pSize-npSize >= 2){
		//remove elements from primes until pSize-npSize >=1
		sort(primes.begin(),primes.end());
		int indx = 0;
		while(pSize-npSize >1 ){
			penalty +=  primes[indx++];
			pSize--;
		}
	}
	else if(npSize-pSize >= 2){
		//or remove elements from nprimes until npSize-pSize >=1
		sort(nprimes.begin(),nprimes.end());
		int indx = 0;
		while(npSize-pSize >1 ){
			penalty +=  nprimes[indx++];
			npSize--;
		}
	}
	return penalty;

}
int main()
{	
	int arr[] = {1,6,3,4,7,6,11,8,10,12};
	int n = sizeof(arr)/sizeof(int);
	cout<<minPenalty(n,arr)<<endl;
	return 0;
}
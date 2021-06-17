#include<iostream>
using namespace std;

void primeSieve(int *p){

	//mark all odd numbers as potential prime candidates
	for(int i = 3; i<= 1000000; i+=2){
		p[i] = 1;
	}

	//prime sieve
	for(long long i = 3; i<= 1000000; i+=2){
		if(p[i] == 1){
			for(long long j = i*i; j<=1000000; j+=i){
				p[j] = 0;
			}
		}
	}

	//special case
	p[0] = p[1] = 0;
	p[2] = 1;

}
int main(){
	
	int t;
	cin>>t;
	int a,b;
	int p[1000000] = {0};
	
	primeSieve(p);

	int cumSum[1000000] = {0};
	
	for(int i = 1; i<=1000000; i++){
		cumSum[i] = cumSum[i-1] + p[i];
	}

	while(t--){
		cin>>a>>b;
		//we need to count the number of prime numbers bw a and b
		cout<<cumSum[b]-cumSum[a-1]<<endl;
	}
	return 0;
}

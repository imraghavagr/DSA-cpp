#include<iostream>
#include<vector>
using namespace std;

vector<int> primeSieve(int *p, int n){

	for(int i = 3; i<=n; i+=2){
		p[i] = 1; 
	}

	for(long long i = 3; i<= n; i+=2){
		if(p[i] == 1){
			for(long long j = i*i; j<= n; j+=i){
				p[j] = 0;
			}
		}
	}

	p[0] = p[1] = 0;
	p[2] = 1;

	vector<int> primes;
	//inserting 2 into the vector of primes
	primes.push_back(2);
	for(int i = 3; i<=n; i+=2){
		if(p[i]){ primes.push_back(i); }
	}

	return primes;
}

vector<int> factorize(int m, vector<int> &primes){
	
	// m is the num whose prime factors are to be found
	//p contains a vector of prime numbers from 0 to n
	vector<int> factors;
	factors.clear(); //this will create an empty vector

	//pick the first prime number, that is on 0 index
	int i = 0;
	int p = primes[0];

	while(p*p<=m){
		if(m%p == 0){
			factors.push_back(p);
			while(m%p == 0){
				m = m/p;
			}
		}
		//go to the next position
		i++;
		p = primes[i];
	}
	if(m != 1){
		factors.push_back(m);
	}
	return factors;
}
int main(){

	int n = 1000000;
	int p[n]  = {0};
	
	//we will store all the prime numbers till from 0 to n in following vector
	vector<int> primes = primeSieve(p,n);


    int no;
    cin>>no;
    vector<int> factors = factorize(no, primes);

    for(auto it: factors){
        cout<<it<<" "<<endl;
    }

    //once we have all the prime factors, just sum it 
    int sum = 0;
    for(int i = 0; i<factors.size(); i++){
        sum += factors[i];
    }
    cout<<sum<<endl;

	return 0;
}

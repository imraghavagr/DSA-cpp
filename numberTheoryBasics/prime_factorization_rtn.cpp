#include<iostream>
#include<vector>
using namespace std;

void printPrimeFactors(int n){
	vector<pair<int,int>> factors;
	int count = 0;
	for(int i = 2; i*i<=n; i++){
		if(n%i == 0){
			//keep on dividing by i while it is divisible
			while(n%i == 0){
				count++;
				n = n/i;
			}
			factors.push_back(make_pair(i,count));
		}
	}
	if(n != 1){
		//whatever is left is a prime number in itself
		factors.push_back(make_pair(n,1));
	}
	for(auto it:factors){
		cout<<it.first<<"^"<<it.second<<endl;
	}
	return;
}

int main(){

	int n;
	cin>>n;

	printPrimeFactors(n);



	return 0;
}

#include<iostream>
using namespace std;

bool f(long long * in, int n){
	//base case
	if(n == 1 or n == 0){
		return true;
	}

	//rec case
	if(in[0] < in[1]){
		f(in+1,n-1);
	}
	else{
		return false;
	}

}

int main(){

	int n;
	cin>>n;
	long long in[1000];
	for(long long i = 0; i<n; i++){
		cin>>in[i];
	}

	if(f(in,n)){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
}
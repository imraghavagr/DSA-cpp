#include<iostream>
using namespace std;

void dec(int n){

	//base case
	if(n==1){
		cout<<n<<" ";
		return;
	}

	//rec case
	cout<<n<<" ";
	dec(n-1);

}
void inc(int n){
	//base case
	if(n == 1){
		cout<<n<<" ";
		return;
	}

	//rec case
	inc(n-1);
	cout<<n<<" ";
	

}

int main(){

	int n;
	cin>>n;

	dec(n);
	cout<<endl;
	inc(n);

	return 0;
}

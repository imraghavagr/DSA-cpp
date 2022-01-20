#include<iostream>
using namespace std;

//increasing seq
int f1(int n){
	
	//base case
	if(n == 1)
		return;
	//rec case 
	
	//print remaining 
	f1(n-1);
	 
}

//decreasing seq
int f2(int n){

}

int main(){
	
	int n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;

}

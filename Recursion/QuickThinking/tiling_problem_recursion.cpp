#include<iostream>
using namespace std;

int findTotalWays(int n){

	//base case
	if(n <=3){
		return 1;
	}


	//rec case
	return findTotalWays(n-1) + findTotalWays(n-4);

}

int main(){

	int n;
	cin>>n;

	cout<<findTotalWays(n)<<endl;


	return 0;
}

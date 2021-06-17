#include<iostream>
using namespace std;
//2048 --> Two zero four eight

char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printSpellings(int n){

	//base case
	if(n == 0){
		return;
	}

	//rec case
	//first print spellings of 204
	printSpellings(n/10);
	int digit = n%10;
	cout<<words[digit]<<" ";

}
int main(){

	int n;
	cin>>n;
	printSpellings(n);
	return 0;
}

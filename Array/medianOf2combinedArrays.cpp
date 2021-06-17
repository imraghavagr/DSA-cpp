#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;
	int resultArray[2000];
	int N = 2*n;
	for(int i=0;i<N;i++){
		cin>>resultArray[i];
	}

	sort(resultArray,resultArray+N);

	int a = (N/2) - 1;
	int b = N/2;
	cout<<(resultArray[a]+resultArray[b])/2<<endl;


	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	int n; 
	cin>>n;
	int arr[1000];
	int maxElem = arr[0];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		maxElem = max(maxElem,arr[i]);
	}

	int freq[maxElem] = {0};

	for(int i = 0; i<n; i++){
		freq[arr[i]] += 1;
	}
	int max = 0;
	for(int i = 0; i<=maxElem; i++){
		if(freq[i] > max){
			max = i;
		}
	}
	cout<<max<<endl;
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
/*
	1 0 0 0 2 2 2
	op = 4		
*/
int ArrayChallenge(int arr[], int arrLength){

	//return 0 if no '2' is present
	auto it = find(arr, arr+arrLength,2);
	if((it -arr) == arrLength)
		return 0;

	//serch for idx of 1
	it = find(arr,arr+arrLength, 1);
	int idx = it-arr; // idx will store the idx of 1 present in array
	
	//search for the first occur of 2 on lhs of 1
	int Lidx = arrLength,Ridx = arrLength;
	for(int i = idx-1; i>=0; i--){
		if(arr[i] == 2){
			Lidx = i;
			break;
		}
	}

	//search for the first occur of 2 on RHS of 1
	for(int i = idx+1; i<arrLength; i++){
		if(arr[i] == 2){
			Ridx = i;
			break;
		}
	}
	return abs(min(Lidx,Ridx)-idx);
}
int main(){
	int arr[] = {4,1,0};
	int n = sizeof(arr)/sizeof(int);
	cout<<ArrayChallenge(arr,n)<<endl;
}


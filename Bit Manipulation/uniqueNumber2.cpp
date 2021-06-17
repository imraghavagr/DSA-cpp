#include<iostream>
#include<algorithm>
using namespace std;

//given a array of n numbers where every number
//repeats twice, except two numbers
//find those unique numbers in an efficient way

int main(){

	int n;
	cin>>n;
	
	int arr[100000]; 
	int result = 0;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		result = result ^ arr[i];
	}

	//lets say, numbers we are finding are a, b
	//at this point, result will be a^b

	int temp = result;

	//now lets try to find out the position of first set bit from right in the result
	int pos = 0;
	while(temp & 1 == 0){
		pos++;
		temp = temp >> 1;
	}
	//the first set bit from right in result is at position 'pos'

	//now we need to check which numbers have a set bit at that position 
	int a = 0; 
	int b = 0;
	int mask = (1 << pos);
	for(int i = 0; i<n; i++){
		if((arr[i] & mask)>0){a = a ^ arr[i]; }
	}

	//finding b
	b = result ^ a;
	cout<<min(a,b)<<" "<<max(a,b)<<endl;



	return 0;
}

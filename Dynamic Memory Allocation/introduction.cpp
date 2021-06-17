// dynamic vs static
#include<iostream>
using namespace std;

int main(){

	//creating a static array (static allocation + deallocation handled by compiler)
	int a[1000];
	int n = 5;
	cout<<sizeof(a)<<endl; //size of a will be the size of entire array, that is 4*1000 = 4000
	int count = 0;
	for(int i =0; i<n; i++){
		a[i] =  count++;
	}
	cout<<sizeof(a)<<endl;

	//creating a dynamic array
	//new int[] will give address of the allocated 1000 blocks of memory in the heap/dynamic memory
	//and we will store that address into a pointr, which will be in static memory
	int *b = new int[1000]; //dynamic allocation done by programmer.
	cout<<sizeof(b)<<endl; //whereas size of b will be size of the single integer bucket, as it is a pointer

	delete []b; //dynammic deallocation handled by programmer


	//suppose we want to allocate all the elements as zero in a dynamic array
	int *c = new int[5]{0}; //now all the 5 elements of this array are zero
	delete []c;

	int *ptr = new int;
	delete ptr;

	return 0;
}

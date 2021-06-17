#include<iostream>
using namespace std;

int main(){

	int r,c;
	r = 3;
	c = 3;


	int **arr = new int*[r];
	//here we created a 1-D array of pointer type of r size in heap
	//and we created a double pointer pointing to the address of the first block of that 1-D array 


	//creating 2D array
	for(int i =0; i<r; i++){

		//humko bas ically r now of 1D arrays banane hai
		//and we will store the addresses of all those 1-D arrays in an another array

		arr[i] = new int[c]{0}; //initialising all elements as zero
	}

	//printing the output

	for(int i =0; i<r; i++){
		for(int j=0; j<c; j++){
			//arr[i][j] = value++; //initialisation with some other value
			cout<<arr[i][j]<<" " ;
		}
		cout<<endl;
	}

	return 0;
}

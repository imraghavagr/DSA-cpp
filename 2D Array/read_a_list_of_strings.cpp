#include<iostream>
using namespace std;

//Read a list of strings and we will store them in a 2D character array

int main(){

	int n;
	cin>>n;
	cin.get(); // to consume the exta enter that is pressed after entering n;

	char a[100][100];
	
	for(int i = 0; i<n; i++){
		cin.getline(a[i], 1000); //by default delim = \n

	}
	//print out all the strings
	for(int i=0; i<n; i++){
		cout<<a[i]<<endl;
	}

	return 0;
}

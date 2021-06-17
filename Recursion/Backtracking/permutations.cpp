#include<iostream>
using namespace std;

void generatePermut(char in[], int i){
	//base case
	if(in[i] == '\0'){
		cout<<in<<endl;
		return;
	}

	//rec case
	for(int j =i;in[j] != '\0'; j++){
		swap(in[i],in[j]);
		generatePermut(in,i+1);
		swap(in[i],in[j]);
	}
}

int main(){

	char in[100];
	cin>>in;
	int i =0;
	generatePermut(in,i);

	return 0;
}

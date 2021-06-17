#include<iostream>
using namespace std;

char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PORS","TUV","WXYZ"};

void generateNames(char *in , char *out, int i, int j){
	//base case
	if(in[i] == '\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}


	//rec case
	int digit = in[i] - '0';

	if(digit == 1 or digit == 0){
		generateNames(in, out,i+1,j);
	}
	for(int k =0; keypad[digit][k] != '\0'; k++){
		out[j] = keypad[digit][k];
		//fill the remaining part
		generateNames(in,out,i+1,j+1);
	}
	return;
}
int main(){

	char in[100];
	cin>>in;

	char out[100];
	//0 and 0 is the idx of input and output array
	generateNames(in,out,0,0);


	return 0;
}

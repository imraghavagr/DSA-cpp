#include<iostream>
using namespace std;

void generateStrings(char *in, char *out, int i, int j){

	//base case
	if(in[i] == '\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}

	//rec case
	//choosing 1 digit at a time
	int digit = in[i] - '0';
	if(digit == 0){
		return;
		generateStrings(in,out,i+1,j);
	}
	else{
		char ch = digit + 'A' - 1;
		out[j] = ch;
		generateStrings(in,out,i+1,j+1);
	}
	

	//choosing 2 digits at a time
	if(in[i+1] != '\0'){
		int secondDigit = in[i+1] - '0';
		int num = (digit*10) + secondDigit;
		if(num<=26){
			char ch = num + 'A' - 1;
			out[j] = ch;
			generateStrings(in, out, i+2, j+1);
		}
	}

	return;

}


int main(){

	char in[100];
	cin>>in;

	char out[100];

	generateStrings(in,out,0,0);

	return 0;
}

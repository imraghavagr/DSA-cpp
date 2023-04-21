#include<iostream>
using namespace std;

char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PORS","TUV","WXYZ"};

void generateNames(string &in , string &op, int i){
	//base case
	if(i >= in.length()){
		cout<<op<<endl;
		return;
	}


	//rec case
	int digit = in[i] - '0';
    //iterate through the alphabets of current digit 
	for(int k =0; keypad[digit][k] != '\0'; k++){
		// op[j] = keypad[digit][k];
        op.push_back(keypad[digit][k]);
		//fill the remaining part
		generateNames(in,op,i+1);
        op.pop_back();
	}
	return;
}
int main(){

	int n;
    cin>>n;
    string ip = to_string(n);
	string op;	
    //0 is the index of input 
	generateNames(ip,op,0);
	return 0;
}

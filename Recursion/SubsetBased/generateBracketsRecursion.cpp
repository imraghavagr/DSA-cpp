#include<iostream>
using namespace std;
void generateBrackets(char *out, int n, int idx, int open_cnt,int close_cnt){

	//base case
	if(idx == 2*n){
		out[idx]= '\0';
		cout<<out<<endl;
		return;
	}
	//rec cases
	if(open_cnt < n){
		//this means we can put open bracket at this idx of out array
		out[idx] = '(';
		generateBrackets(out,n,idx+1,open_cnt+1,close_cnt);
	}
	if(close_cnt < open_cnt){
		//we can put closing brackets
		out[idx] = ')';
		generateBrackets(out,n,idx+1,open_cnt,close_cnt+1);
	}


}
int main(){

	int n;
	cin>>n;
	char out[1000];
	int idx = 0;
	generateBrackets(out,n,idx,0,0);
	return 0;
}

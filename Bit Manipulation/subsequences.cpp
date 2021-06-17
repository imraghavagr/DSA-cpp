#include<iostream>
using namespace std;
void generateSubs(char a[], int i, char out[], int j ){
	//base case
	if(a[i] == '\0'){
		out[j] = '\0';
		cout<<out;
		return;
	}

	//rec case

	//include current char
	out[j] = a[i];
	generateSubs(a,i+1,out,j+1);

	//excluding the current char
	generateSubs(a,i+1,out,j);


}
int main(){

	char a[1000];
	int i = 0;
	cin>>a;
	char ouput[100];
	char j = 0;
	
	generateSubs(a,i,ouput,j);

	return 0;
}

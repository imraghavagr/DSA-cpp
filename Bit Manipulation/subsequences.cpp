#include<iostream>
#include<cstring>
using namespace std;
/*
Finding subsequences
abc 
0 to 2^n - 1
i.e. 0 to (1<<n) - 1

*/
void filterChars(int n, char a[]){
	int j = 0;
	while(n>0){
		int lb = (n&1);
		if(lb){
			cout<<a[j];
		}
		j++;
		n = n>>1;
	}
}
int main(){

	char a[1000];
	cin>>a;
	int n = strlen(a);
	for(int i = 0; i < (1<<n); i++){
		filterChars(i,a);
		cout<<" ";
	}
	return 0;
}

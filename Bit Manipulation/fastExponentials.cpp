#include<iostream>
using namespace std;

int fastPower(int a, int b){
	int ans = 1;
	while(b>0){
		if(b&1 == 1){ ans = ans * a;}
		a = a*a;
		b = b>>1;
	}
	return ans;
}

int main(){

	int a,b;
	cin>>a>>b;
	cout<<fastPower(a,b)<<endl;

	return 0;
}

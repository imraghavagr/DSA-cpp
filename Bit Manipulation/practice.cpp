#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t>0){
		int x;
		cin>>x;
		int count = 0;
		while(x>0){
			if((x & 1) == 1){count ++;}
			x = x>>1;
		}
		cout<<count<<endl;
		t--;
	}

	return 0;
}

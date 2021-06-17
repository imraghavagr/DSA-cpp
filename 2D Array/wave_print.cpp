#include<iostream>
using namespace std;

void wavePrint(int a[][100], int m, int n){
	
	for(int i=0; i<n; i++){
		
		if(i%2 == 0){
			for(int j=0; j<m; j++){
				cout<<a[j][i]<<" ";
			}	
			cout<<endl;
		}
		else{
			for(int j=m-1; j>=0; j--){
				cout<<a[j][i]<<" ";
			}
			cout<<endl;
		}
		
	}

}
int main(){

	int a[100][100];
	int m,n;
	cin>>m>>n;
	int count =0;
	
	for(int i=0; i<m; i++){
		for(int j = 0; j<n; j++){
			a[i][j] = ++count;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	wavePrint(a,m,n);

	return 0;
}
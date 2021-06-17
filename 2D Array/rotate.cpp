#include<iostream>
#include<algorithm>
using namespace std;
void rotate(int a[][100], int m, int n){
	
	//reverse each row
	for(int row = 0; row<n; row++){
		int startCol = 0;
		int endCol = n-1;
		while(startCol<endCol){
			swap(a[row][startCol], a[row][endCol]);
			startCol++;
			endCol--;
		}
	}

	//take transpose
	//iterate either on the upper traingle or on the lower triagle
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			//lower triangle
			if(i<j){
				swap(a[i][j], a[j][i]);
			}
		}
	}

}
void rotate_stl(int a[][100], int m, int n){
	
	//reverse each row
	//same thing using STL reverse(start_container, end_container) methods
	for(int row = 0; row<n; row++){
		reverse(a[row],a[row]+n);
	}

	//take transpose
	//iterate either on the upper traingle or on the lower triagle
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			//lower triangle
			if(i<j){
				swap(a[i][j], a[j][i]);
			}
		}
	}

}
void display(int a[][100], int m, int n){
	for(int i=0; i<m; i++){
		for(int j = 0; j<n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
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
	cout<<endl;

	rotate(a,m,n);
	display(a,m,n);

	rotate_stl(a,m,n);
	display(a,m,n);

	return 0;
}

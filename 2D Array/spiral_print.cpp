#include<iostream>
using namespace std;

void spiralPrint(int a[][100], int m, int n){
	int startRow = 0;
	int endRow = m-1;
	int startCol = 0;
	int endCol = n-1;
	while(startRow<=endRow and startCol<= endCol){

		//first row
		for(int i =startCol; i<=endCol; i++){
			cout<<a[startRow][i]<<" ";
		}
		startRow++;

		//last col
		for(int i = startRow;i<=endRow; i++ ){
			cout<<a[i][endCol]<<" ";
		}
		endCol--;

		//bottom row
		if(endRow>startRow){
			for(int i=endCol; i>=startCol; i--){
				cout<<a[endRow][i]<<" ";
			}
			endRow--;
		}
		
		//left most col
		if(endCol>startCol){
			for(int i=endRow; i>=startRow; i--){
				cout<<a[i][startCol]<<" ";
			}
			startCol++;
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

	spiralPrint(a,m,n);


	return 0;
}
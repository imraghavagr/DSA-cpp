#include<iostream>
using namespace std;
//given a SORTED 2D array, find the given key 'k'
void staricase_search(int a[][100], int m, int n, int key){

	int i = 0; 
	int j = n-1;
	if(key < a[0][0] or key > a[m-1][n-1])
	{
		cout<<"key not found";
		return;
	}
	while(i>=0 and j>=0){
		if(a[i][j] > key){
			j--;
		}
		else if(a[i][j] < key){
			i++;
		}
		else{
			cout<<key<<" found at index ("<<i<<","<<j<<")"<<endl;
			return;
		}
	}
	cout<<"Key not found";
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
	int key;
	cin>>key;

	staricase_search(a,m,n,key);

	return 0;
}

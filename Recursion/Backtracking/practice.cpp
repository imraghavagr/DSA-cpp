#include<iostream>
using namespace std;
int count = 0;
bool ratINMaze(char in[10][10], int out[10][10], int i, int j, int m, int n){

	//base case
	if(i == m-1 and j == n-1){
		out[i][j] = 1;
		count++;
		for(int i = 0; i<m; i++){
			for (int j = 0; j<n; j++){
				cout<<out[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	//rec case
	if(i>m-1 or j>n-1){return false;}
	if(in[i][j] == 'X'){return false;}

	out[i][j] = 1;
	
	bool rightSuccess = ratINMaze(in, out, i,j+1, m,n);
	bool downSuccess = ratINMaze(in, out, i+1,j, m,n);

	out[i][j] = 0;

	if(rightSuccess or downSuccess){return true;}
	else{return false;}
}
int main(){

	char maze[10][10] = {
						"00X0",
						"X000",
						"000X",
						"0X00"
	};

	int soln[10][10] = {0};
	int m = 4, n = 4; 
	for(int i = 0; i<m; i++){
		for(int j = 0; j<n; j++){
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	bool ans = ratINMaze(maze,soln,0,0,m,n);
	cout<<endl<<"Total number of paths are : "<<count<<endl;
	if(!ans){
		cout<<"Path does not exists! ";
	}


	return 0;
}

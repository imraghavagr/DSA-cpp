#include<iostream>
using namespace std;

int count = 0;
//i,j - index of current cell
// m,n - coordinates of last cell/destination cell
bool ratINMaze(char maze[10][10], int soln[][10], int i, int j, int m,int n){
	//base case
	if(i == m && j == n){
		//put 1 in the position where we went
		soln[m][n] = 1;
		count ++;

		//print the path
		for(int i = 0; i<=m; i++){
			for(int j = 0; j<=n; j++){
				cout<<soln[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;

		return true;
	}
	//rec case
	//rat must be inside the grid
	if(i>m || j>n){
		return false;
	}
	//cell is blocked
	if(maze[i][j] == 'X'){
		return false;
	}

	//assume solution exists through current cell
	soln[i][j] = 1;

	bool rightSuccess = ratINMaze(maze,soln,i,j+1,m,n);
	bool downSuccess = ratINMaze(maze,soln,i+1,j,m,n);
	
	//Backtracking
	soln[i][j] = 0; // peeche aate samay hum 0 krte jarahe hai
	
	if(rightSuccess || downSuccess){
		return true;
	}
	else{
		return false;
	}
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

	bool ans = ratINMaze(maze,soln,0,0,m-1,n-1);
	cout<<endl<<"Total number of paths are : "<<count<<endl;
	if(!ans){
		cout<<"Path does not exists! ";
	}

	return 0;
}

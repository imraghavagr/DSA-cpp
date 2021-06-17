#include<iostream>
using namespace std;
bool isSafe(int board[][10], int i, int j, int n){

	//right diagonal
	int x = i;
	int y = j;
	while(x>=0 and y < n){
		if(board[x][y] == 1){return false;}
		x--;
		y++;
	}

	//left diagonal
	x = i;
	y = j;
	while(x>=0 and y >=0){
		if(board[x][y] == 1){return false;}
		x--;
		y--;
	}

	//vertical up
	for(int row = 0; row<i; row ++){
		if(board[row][j] == 1){ return false;}
	}


	//neeche chek krne ki jaroorat ni hya kyuki we are filling row by row
	return true;

}
bool placeQueens(int board[][10], int i, int n){

	//base case
	if(i == n){
		//successfully placed queens in 0 to n-1 index rows 
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(board[i][j] == 1){cout<<"Q"<<" "; }
				else{ cout<<"#"<<" ";}
				
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	//rec case
	//place the queen in current row and remaining queens will be placed by recursion in remaining rows
	for(int j = 0; j<n; j++){
		//check if i,j th position is safe to place the queen
		if(isSafe(board,i,j,n)){
			//place the queen assuming i,j is right postion
			board[i][j] = 1;
			bool canPlaceNextQueen = placeQueens(board, i+1, n);
			if(canPlaceNextQueen){return true;}
			//yaha flow aaraha agar iska matlab i,j is not correct position
			//backtrack
			board[i][j] = 0;
		}
	}
	//we have tried for all positions in current row but coudn't place a queen
	return false;
}

int main(){

	int n;
	cin>>n;

	int board[10][10] = {0};

	placeQueens(board,0,n);


	return 0;
}

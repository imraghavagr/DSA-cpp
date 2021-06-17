#include<iostream>
using namespace std;
void move(int n, char src, char helper, char dest){

	//base case
		if(n == 0){
		return;
	}
 
	//rec case

	//move n-1 disks from source to helper
	move(n-1, src,dest,helper);
	// now to move one disk from source to dest
	cout<<"Shift disk "<<n<<" from "<<src<<" to " <<dest<<endl;
	//now shift the disks from helper to dest
	move(n-1,helper,src,dest);

}
int main(){

	int n; //no. of disks
	cin>>n;
	//source - 'A', des - 'C', helper - 'B'
	move(n,'A','B','C');
	return 0;
}

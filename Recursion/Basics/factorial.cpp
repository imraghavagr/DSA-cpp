#include<iostream>
using namespace std;

int fact(int n){

	//base case
	if(n == 0){
		return 1;
	}
	//recursive case
	int small_ans = fact(n-1);
	int ans = n * small_ans;
	return ans;

	//return n*fact(n-1);

}
int main(){

	int n;
	cin>>n;
	cout<<fact(n);
	return 0;
}

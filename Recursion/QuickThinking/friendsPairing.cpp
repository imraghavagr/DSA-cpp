#include<iostream>
using namespace std;
//there are n people and every person can either go alone on a bike
//or can go as a couple
//find the number of ways n people can go to the party.

 // Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
int f(int n){

	//base case
	if(n == 0 or n == 1){
		return 1;
	}

	//rec case
	int ans1 = f(n-1);
	int ans2 = (nCr(n-1,1))*(f(n-2));
	return ans1+ans2;
}

int main(){

	int n;
	cin>>n;

	cout<<f(n)<<endl;

	return 0;
}

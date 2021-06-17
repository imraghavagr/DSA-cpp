#include<iostream>
using namespace std;
int f(int weights[], int prices[], int n, int c){
	//base case
	if(n == 0 or c == 0){
		return 0;
	}

	//rec case
	int ans = 0;
	int inc,exc;
	inc = exc = 0; //at the begining, both including and excluding profit is negative
	
	//case 1 - last item included
	if(weights[n-1] <= c){
		inc = prices[n-1]+f(weights,prices,n-1,c-(weights[n-1]));
	}
	//case 2 - last item not included
	exc = f(weights,prices,n-1,c);

	ans = max(inc,exc);
	return ans;
}

int main(){

	int weights[] = {1,2,3,5};
	int prices[] = {40,20,30,100};
	int n = 4; //no of items
	int c = 7; // max capacity of bag

	cout<<f(weights,prices,n,c)<<endl;

	return 0;
}

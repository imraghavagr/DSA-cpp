//given idian currency 
#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
	return a<=b;
}

int main(){

	int currency[] = {1,2,5,10,20,50,100,200,500,2000};
	int n = sizeof(currency)/sizeof(int);
	int money = 169; 
	// 168 - 100 = 68
	//68-50 = 18
	//18 - 10 = 8
	//8 - 5 = 3
	//3 - 2 = 1
	//humko harbaar currency array se apni key(money) se nearest choti currency leni hai

	/*int lb = lower_bound(currency, currency+n, money) - currency;
	by this we are getting the nearest greater currency of the  key.
	but we want reverse of it.. so lets write our comparator()
	*/
	int m = 0;
	while(money>0){
		int lb = lower_bound(currency, currency+n, money, compare) - currency -1;
		m = currency[lb];
		cout<<m<<" ";

		money -= m;
	}
	cout<<endl;
	

	return 0;
}

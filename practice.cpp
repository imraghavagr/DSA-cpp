#include<bits/stdc++.h>
using namespace std;
int findEarliestMonth(vector<int> stockPrice){
	//brute force 
	int ans = -1;
	int minValue = INT_MAX;
	// cout<<"coming here"<<endl;
	for(int i = 0; i<stockPrice.size(); i++){
		// cout<<"hey"<<" ";
		long long int avg1 = 0;
		long long int avg2 = 0;
		//lets find the avg1
		for(int j = 0; j<=i; j++){
			avg1 += stockPrice[j];
		}
		avg1 = floor(avg1/(i+1));
		cout<<avg1<<" ";
		for(int j = i+1; j<stockPrice.size(); j++){
			avg2 += stockPrice[j];
		}
		avg2 = floor(avg2/(stockPrice.size()-i-1));
		cout<<avg2<<" ";
		int diff = abs(avg1 - avg2);
		// cout<<diff<<" ";
		if(diff<minValue){
			// cout<<"hey"<<endl;
			minValue = diff;
			ans = i+1;
		}
	}
	return ans;
}
int main()
{	
	vector<int> stockPrice{1,3,2,3};
	cout<<findEarliestMonth(stockPrice)<<endl;
	return 0;
}
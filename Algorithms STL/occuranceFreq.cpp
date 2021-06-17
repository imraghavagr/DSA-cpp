//given a sorted array 
//find the occurance frequency of given element
#include<iostream>
#include<algorithm>

using namespace std;

int main(){

	int arr[] = {1,2,3,3,4,5,3,6};
	int n = sizeof(arr)/sizeof(n);

	//sorting the array (inbuilt sort)
	sort(arr,arr+n);

	int key = 3;
	
	bool present = binary_search(arr,arr+n, key);
	if(!present){
		cout<<"Element not present"<<endl;
	}
	else{
		auto lb = lower_bound(arr,arr+n, key);\
		cout<<"Lower bound of the key = "<<lb-arr<<endl;
		auto ub = upper_bound(arr,arr+n, key);\
		cout<<"Upper bound of the key = "<<ub-arr<<endl;

		int freq = ub-lb;
		cout<<"Occurance freq of key = "<<freq<<endl;
	} 
	return 0;
}

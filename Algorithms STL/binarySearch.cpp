//built in binary search
//binary_search(arr,arr+n) //works for sorted array only 
//more efficient than find()
//binary search takes nlog(n)
#include<iostream>
#include<algorithm>

using namespace std;

int main(){

	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(n);

	int key = 15;
	
	bool present = binary_search(arr,arr+n, key);
	if(present){
		cout<<"Present"<<endl;
	}
	else{
		cout<<"Not present"<<endl;
	} 
	return 0;
}

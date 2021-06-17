#include<iostream>
#include<cstring>
using namespace std;
//Read N, followed by N string and print the largest string and its length
//We will not store all the strings
// we will the largest string till now
// and we will store the current string
int main(){
	
	int n;
	cin>>n;
	cin.get(); //for consuming this enter
	
	char a[1000];
	char largest[1000];
	
	int len = 0;
	int largest_len = 0;

	for(int i=0; i<n; i++){
		cin.getline(a,1000);
		len = strlen(a);
		if(len > largest_len){
			largest_len = len;
			strcpy(largest, a);
		}
	}
	cout<<largest<<" and length = "<<largest_len<<endl;
	return 0;
}

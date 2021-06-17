#include<iostream>
#include<vector>
using namespace std;

int main(){

	//different ways to declare and initialise a vector

	vector<int> a;

	vector<int> b(5,10); // means 5 integers with value 10 

	vector<int> c(b.begin(), b.end());// copy all values of b to vector c

	vector<int> d{1,2,3,4,5}; //declaring and intitialising with values 1-5



	//iterating over a vector

	//1
	for(int i = 0; i<b.size(); i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	//2
	for(auto it = c.begin(); it != c.end(); it++){
		cout<<(*it)<<" ";
	}
	cout<<endl;
	//3rd
	for(int x : d){
		cout<<x<<" ";
	}
	cout<<endl;

	//taking user input for vector a
	int n;
	cin>>n;

	for(int i =0; i<n; i++){
		int no;
		cin>>no;
		a.push_back(no);
	}
	for(int x : a){
		cout<<x<<" ";
	}
	cout<<endl;

	//vector.push_back(value) does two things
	//adds element to the end of the vector
	//doubles the size of the vector if required


	//notice the difference between vectors d and a, both have 5 values but are created differently

	cout<<d.size()<<endl; //gives the number of elements present in vector
	cout<<d.capacity()<<endl; //returns the underlying capacity of the vector
	cout<<d.max_size()<<endl; //returns the max size that can be allocated in the mem acrdng to the system

	cout<<a.size()<<endl; 
	cout<<a.capacity()<<endl;
	cout<<a.max_size()<<endl;

	cout<<endl;


	return 0;
}

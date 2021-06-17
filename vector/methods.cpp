#include<iostream>
#include<vector>
using namespace std;

int main(){

	vector<int> v;

	//push_back - add elements at the end of the vector
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	//pop_back - removes the last element
	v.pop_back();
	cout<<v.size()<<endl;
	for(int x : v){
		cout<<x<<" ";
	}
	cout<<endl;

	//insert method - for adding elements in any position of the vector
	v.insert(v.begin()+1, 15); //will insert 15 after the first position 
	for(int x : v){
		cout<<x<<" ";
	}
	cout<<endl;

	//we can insert multiple instances of same element too
	v.insert(v.begin()+2, 5,0); //this will add 5 number of zeros after the 2nd position
	for(int x : v){
		cout<<x<<" ";
	}
	cout<<endl;

	//erase method - erase any element
	//cuurent vector v = 10,15,0,0,0,0,0,20
	v.erase(v.begin() + 1); //- will remove 15 from the vector, i.e element after the 1st position
	for(int x : v){
		cout<<x<<" ";
	}
	cout<<endl;

	//remove all elements
	v.clear(); // size will be zero but capacity will remain same
	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;

	//check if a vector is empty
	if(v.empty()){cout<<"Vector is empty"<<endl;}

	
	v.push_back(10);
	v.push_back(15);
	v.push_back(20);

	// front and back - returns first and last element respectively
	cout<<v.front()<<endl;
	cout<<v.back()<<endl;

	//reserve method - since doubling is expensive while push_back operation, 
	//we can reserve some memory for our vector

	vector<int> a;
	int n = 1000;
	a.reserve(n);

	cout<<a.size()<<endl;
	cout<<a.capacity()<<endl; //capacity will be 1000
	














	return 0;
}

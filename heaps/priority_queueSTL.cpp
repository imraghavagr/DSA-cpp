#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

// for defining custom priority. 
struct comp{
	bool operator()(vector<int> a, vector<int> b){

		//for min heap
		return a[2]>b[2];//will consider the 2nd index element as priority element 

		//return a[2]<b[2] for max heap ...
	}
};

int main()
{
	
	vector<int> v1 = {1,2,3,4,5,6,7};
	
	//to make a normal max heap, which considers 0th element in the container as the priority element 
	priority_queue<int> q1(v1.begin(), v1.end());
	while(!q1.empty()){
		cout<<q1.top()<<" ";
		q1.pop();
	}
	cout<<endl;

	//to make a min heap 
	priority_queue<int, vector<int>, greater<>> q2(v1.begin(), v1.end()); //vector<int> is the container which will be used to store
													//the overall queue.
													//greater<> will result in making maxheap
	while(!q2.empty()){
		cout<<q2.top()<<" ";
		q2.pop();
	}
	cout<<endl;

	//lets try to store vector<vector<int>> inside the priority_queue now 
	vector<vector<int>> v = {{1,2,3},{4,5,3},{5,6,54},{0,97,56}};

	//to make a normal max heap, which considers 0th element in the container as the priority element 	
	priority_queue<vector<int>> q3;
	
	for(int i = 0; i<v.size(); i++){
		q3.push(v[i]);
	}
	
	while(!q3.empty()){
		vector<int> temp = q3.top();
		q3.pop();
		for(int x : temp)cout<<x<<" ";
		cout<<endl;
	}

	//to make a normal min heap, which considers 0th element in the container as the priority element 	
	priority_queue<vector<int>, vector<vector<int>>, greater<>> q4;
	for(int i = 0; i<v.size(); i++){
		q4.push(v[i]);
	}
	
	while(!q4.empty()){
		vector<int> temp = q4.top();
		q4.pop();
		for(int x : temp)cout<<x<<" ";
		cout<<endl;
	}

	//to customize the priority thing in any way we want 

	priority_queue<vector<int>, vector<vector<int>>, comp> q5;
	for(int i = 0; i<v.size(); i++){
		q5.push(v[i]);
	}
	
	while(!q5.empty()){
		vector<int> temp = q5.top();
		q5.pop();
		for(int x : temp)cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
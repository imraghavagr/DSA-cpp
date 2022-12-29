#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct comp{
	bool operator()(vector<int> a, vector<int> b){
		//for min heap
		return a[2]>b[2];

		//return a[2]<b[2] for max heap ...
	}
};

int main()
{
	vector<vector<int>> v = {{1,2,3},{4,5,3},{5,6,54},{0,97,56}};
	priority_queue<vector<int>, vector<vector<int>>,comp> q;
	
	for(int i = 0; i<v.size(); i++){
		q.push(v[i]);
	}
	
	while(!q.empty()){
		vector<int> temp = q.top();
		q.pop();
		for(int x : temp)cout<<x<<" ";
		cout<<endl;
	}

	// sort(v.begin(), v.end(), compare);
	// for(auto x : v){
	// 	cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
	// }
	return 0;
}
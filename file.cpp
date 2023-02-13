#include<bits/stdc++.h>
using namespace std;
int maxPoints(vector<vector<int>>& points) {
	//eqn of line -> ()y-y1) = m (x-x1)
	//m = (y2-y1)/(x2-x1)
	vector<pair<pair<int,int>, pair<int,int>>> v;
	//form all possible pairs of cordinates
	for(int i = 0; i<points.size(); i++){
		for(int j = i+1; j<points.size(); j++){
			v.push_back({{points[i][0],points[i][1]}, {points[j][0], points[j][1]}});
		}            
	}
	int ans = INT_MIN;
	float m;
	float lhs, rhs;
	for(int i = 0; i<v.size(); i++){
		int temp = 0;
		//now put each point in the eqn of line formed 
		if((v[i].second.first - v[i].first.first) == 0){
			continue;
		}
		m = (v[i].second.second - v[i].first.second)/(v[i].second.first - v[i].first.first);
		
		for(int j = 0; j<points.size(); j++){
			//put j in eqn of line 
			lhs = points[j][1] - v[i].first.second;
			rhs = m*(points[j][0] - v[i].first.first);
			if(lhs == rhs)  temp++;
		}
		ans = max(ans, temp);
	}
	return ans;
}
int main()
{
	vector<vector<int>> v = {{1,1}, {3,2}, {5,3}, {4,1}, {2,3}, {1,4}};
	//[1,1],[2,2],[3,3]
	//[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]
	cout<<maxPoints(v)<<endl;
	return 0;
}
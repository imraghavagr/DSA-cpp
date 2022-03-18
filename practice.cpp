//nearest greater to the right
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> solve(vector<int> v){
	
	vector<int> ans;
	stack<int> s;

	for(int i = v.size()-1; i>=0; i--){
		if(s.empty()){
			ans.push_back(-1);
		}
		else if(v[i]<s.top()){
			ans.push_back(s.top());
		}
		else if(v[i] >= s.top()){
			while(!s.empty() and v[i] >= s.top()){
				s.pop();
			}
			if(s.empty()){
				ans.push_back(-1);
			}
			else{
				ans.push_back(s.top());
			}
		}
		s.push(v[i]);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
	vector<int> v = {8,5,10,6,3,2,7};
	vector<int> ans = solve(v);
	for(int x : ans) cout<<x<<" ";
	cout<<endl;
	return 0;
}
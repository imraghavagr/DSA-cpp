#include<iostream>
#include<vector>

using namespace std;
int main(){
	vector<int> v{3,2,3,5,6,5,2};
	int ans = v[0];
	for(int i = 1;i<v.size(); i++){
		ans = ans ^ v[i];
	}

	cout<<ans<<endl;

	return 0;
}

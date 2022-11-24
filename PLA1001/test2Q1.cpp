#include <bits/stdc++.h>
using namespace std;

void permute(string& a, int l, int r, vector<string> &ans)
{
	// Base case
	if (l == r)
		ans.push_back(a);
	else {
		// Permutations made
		for (int i = l; i <= r; i++) {
			swap(a[l], a[i]);
			permute(a, l + 1, r, ans);
			swap(a[l], a[i]);
		}
	}
}

// Driver Code
int main()
{
	string s;
    cin>>s;
    vector<string> ans;
	int n = s.size();
	permute(s, 0, n - 1,ans);
    sort(ans.begin(), ans.end());
    for(string s : ans){
        cout<<s<<" ";
    }
    cout<<endl;
	return 0;
}
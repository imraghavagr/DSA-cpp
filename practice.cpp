#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> dictWords(string textInput){
	// latt matter cat matter cat
	//cat batman
	//0123456789
	vector<string> ans;
	string s = "";
	string s2 = "";

	for(int i = 0; i<textInput.length(); i++){
		while(!isspace(textInput[i]) and i<textInput.length()){
			s = s + textInput[i];
			//cout<<s<<" ";
			i++;
		}
		int idx = s2.find(s);
		if(idx != -1){
			ans.push_back(s);
		}
		s2 = s2 + " ";
		s2 = s2 + s;
		s = "";
	}
	sort(ans.begin(),ans.end());
	for(int i = 1; i<ans.size(); i++){
		if(ans[i] == ans[i-1]){
			ans.erase(ans.begin()+i,ans.begin()+i+1);
		}
	}
	return ans;
}

int main(){
	string textInput;
	getline(cin,textInput);

	vector<string> ans = dictWords(textInput);
	for(int i = 0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}

	return 0;
}
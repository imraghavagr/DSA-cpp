#include<iostream>
#include<set>
#include<string>
using namespace std;

void generatePermut(char in[], int i, set<string> &s){
	//base case
	if(in[i] == '\0'){
		//cout<<in<<endl;
		string t(in);
		s.insert(t);
		return;
	}

	//rec case
	for(int j =i;in[j] != '\0'; j++){
		swap(in[i],in[j]);
		generatePermut(in,i+1,s);
		swap(in[i],in[j]);
	}
}

int main(){

	char in[100];
	cin>>in;
	set<string> s;
	int i =0;
	generatePermut(in,i,s);
	for(auto str : s){
		cout<<str<<endl;
	}

	return 0;
}

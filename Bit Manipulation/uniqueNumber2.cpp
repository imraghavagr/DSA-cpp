#include<iostream>
#include<vector>
/*
unique number 2

algo:
1. Do xor of all nums 
2. find out the result
3. find pos of set bit in result lets say pos = i;
4. find all nums which contain set bit at pos i
5. do xor of all nums found in step 4 - this will give a
6. b = result ^ a
*/
using namespace std;

pair<int,int> solution(vector<int> &v){
	int result = 0;
	for(int i = 0; i<v.size(); i++){
		result = result ^ v[i];
	}
	//now find the pos of set bit in result
	int temp = result;
	int pos = 0;
	while(temp&1 == 0){
		pos++;
		temp = temp>>1;
	}
	//now lets find what are the numbers that contain set bit at position pos
	int a = 0;
	int b = 0;
	int mask = (1<<pos);
	for(int i = 0; i<v.size(); i++){
		if((v[i]&mask) > 0)	a = a ^ v[i];
    }
	pair<int,int> ans;
	b = result ^ a;
	ans.first = min(a,b);
	ans.second = max(a,b);
	return ans; 
}
int main(){
	
	int n;
	cin>>n;
	vector<int> v;
	for(int i = 0; i<n; i++){
		int num;
		cin>>num;
		v.push_back(num);
	}
	pair<int,int> ans = solution(v);
	cout<<ans.first<<" and "<<ans.second<<endl;
	return 0;
}

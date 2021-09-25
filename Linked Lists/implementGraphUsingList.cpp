
#include<iostream>
#include<list>
using namespace std;

int main(){

	//static list of pairs
	//list<pair<int,int>> l[5]; - here the number of lists is fixed - 5

	//dynamic list of pairs
	list<pair<int,int>> *l;
	int n;
	cin>>n; //number of vertices

	l = new list<pair<int,int>>[n]; //l is now ptr to an array of doubly linked list objects

	int e; //number of edges
	cin>>e;
	for(int i = 0; i<e; i++){
		int x,y,wt; // edge from x to y with a weight wt
		//means x is connected to y with a wight of 'wt'
		//we can make a pair data in list object at index x - pair will be (y,wt)
		cin>>x>>y>>wt;
		l[x].push_back(make_pair(y,wt));
		l[y].push_back(make_pair(x,wt)); //it the edge is bidirectional
	}

	//print the lls
	for(int i = 0; i<n; i++){
		//print every element(pair) of ll
		cout<<"Linked list"<<i<<" -> ";
		for(auto it:l[i]){
			cout<<"{"<<it.first<<","<<it.second<<"},";
		}
		cout<<endl;
	}

	return 0;
}
 
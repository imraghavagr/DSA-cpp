#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(){

	int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    int x;
    cin>>x;
    double y;
    cin>>y;
    cin.get();
    string z;
    getline(cin,z);
    cout<<i+x<<endl;
    cout<<fixed<<setprecision(1)<<d+y<<endl;
    cout<<s+z<<endl;

	return 0;
}

#include<iostream>
#include<time.h>
using namespace std;
int sqrtOfN(long long int n){
	//n=50
	//2 3 .4.5.6.7......12 13 14.........25
	int s = 2;
	int e = n;
	int ans = -1;
	while(s<=e){
		int mid = (s+e)/2;
		if(mid*mid == n){
			return mid;
		}
		else if(mid*mid < n){
			s = mid+1;
			ans = mid;
		}
		else{
			e = mid-1;
		}
	}
	return ans;
}
int sqrt2(long long int n){
	int ans=-1;
	for(int i =2; i<=n/2; i++){
		if(i*i <= n){
			ans = i;
		}
		else{
			break;
		}
	}
	return ans;
}
int main()
{
	long long int n;
	cin>>n;
	time_t s,e;

	//output = int(sqrt(n))
	time(&s);
	cout<<sqrtOfN(n)<<endl;
	time(&e);
	double time_taken = double(e - s);
	cout<<"time = "<<time_taken*1e6<<endl;

	time(&s);
	cout<<sqrt2(n)<<endl;
	time(&e);
	time_taken = double(e-s);
	cout<<"time = "<<time_taken*1e6<<endl;
	return 0;
}
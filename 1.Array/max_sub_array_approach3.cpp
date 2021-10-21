#include<iostream>
#include<climits>
using namespace std;

int modifiedkadane(int *a,int n){
    int sum = INT_MIN; // largest sum
    int currsum = 0;   // current running sum
    int maxelem = INT_MIN; // to find max ele (needed for all negative case ones)
   
    for(int i=0;i<n;i++){
        currsum += a[i];
        if(currsum < 0){
            currsum = 0;
        }
        sum = max(sum,currsum); // till here code is same as kadane algo code
        if(maxelem < a[i]){     // to calculate max ele (needed for all -ve case)
            maxelem = a[i];
        }
    }
    return (maxelem < 0 ? maxelem : sum);//if all are -ve return maxelem, else sum
}
int kadanesAlgo(int*a, int n){
	
	//Kadane's Algorithm for maximum subarray sum
	//this algo will not work if all the elements of the array are negative
	int curr_sum = 0, max_sum = 0;
	
	for(int i=0; i<n; i++){
		curr_sum += a[i];
		if(curr_sum < 0){
			curr_sum = 0;
		}
		if(curr_sum > max_sum )
			max_sum = curr_sum;
	}
	return max_sum;
}

int main(){

	int n;
	cin>>n;
	int a[1000];
	
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int ans = modifiedkadane(a,n);
	cout<<ans<<endl;

	
	return 0;
}
//find the minimum value of (A and B)xor(A or B) for pairs in given array 
//(A&B)^(A|B) = A^B (after simplifying)

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
int main() {
    
    int a[1e6];
    int t;
    cin>>t;
    while(t>0){

        int n;
        cin>>n;
        for(int i =0; i<n; i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int minvalue = INT_MAX;
        int result = 0;
        for(int i=0; i<n-1; i++){
		   result = a[i]^a[i+1];
		   minvalue = min(minvalue, result);

     	}
        cout<<xorResult<<endl;
        t--;
    }
}
cout<<x<<endl;
#include<iostream>
#include<climits>
using namespace std;

int kadaneFinal(vector<int>&v){
	   
    //kadanes algo 
    int s = 0; // 's' will maintain the eligible starting point of the req subarray. 
    int end, start; // end and start will finally contain the required subarray starting and ending indexes.
    // cs = currentSumSoFar, ms = maxSumSoFar
    int cs = 0;
    int ms = 0;
    int maxElem = INT_MIN;
    for(int i = 0; i<v.size(); i++){
        cs += v[i];
        if(cs<0){
            cs = 0;
            s = i+1;
        }
        if(ms<cs){
            ms = cs;
            start = s;
            end = i;
        }
		//below code is just to handle if all the elements are negative
        if(maxElem<v[i]){
            maxElem = v[i];
        }
    }
    if(maxElem<0){
        //this means entire array consists of negative elements
        cout<<maxElem<<endl;
    }
    else{
        cout<<ms<<endl;
        for(int i = start; i<=end; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int main(){

	vector<int> v = {-4,-1,-3,-2,-6,-2,-1,-4};
	kadaneFinal(v);
	return 0;
}
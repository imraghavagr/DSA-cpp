//https://www.interviewbit.com/problems/prettyprint/
/*
Example 1:
Input: A = 4.
Output:
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 

Example 2:
Input: A = 3.
Output:
3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 
*/
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> prettyPrint(int A){
    int n = 2*A - 1;

    vector<vector<int>> arr( n , vector<int> (n, 0));

    for(int i = 0; i<=n/2; i++){
        int j = 0;
        int k = n-1;
        int value = A;
        int reduce = 0;
        while(j<=k){
            arr[i][j] = value;
            arr[i][k] = value;
            j++;
            k--;
            if(reduce<i){
                value--;    
                reduce++;
            }
            
            
        }
    }
    for(int i = n/2+1; i<n; i++){
        int j = 0;
        int k = n-1;
        int value = A;
        int reduce = n-i-1;
        while(j<=k){
            arr[i][j] = value;
            arr[i][k] = value;
            j++;
            k--;
            if(reduce>0){
                value--;    
                reduce--;
            }
            
            
        }
    }
    return arr;

}

int main(){

    
    
    vector<vector<int>> vect;
    int x;
    cin>>x;
    vect = prettyPrint(x);
	for(int i = 0; i < vect.size(); i++)
	{
		for(int j = 0; j < vect[i].size(); j++)
		{
			cout << vect[i][j] << " ";
		}
		cout<< endl;
	}
    return 0;
}
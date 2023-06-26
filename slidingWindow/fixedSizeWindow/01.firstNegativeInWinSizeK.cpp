//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
#include<iostream>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    //sliding window
    list<long long int> l;
    vector<long long> ans;
    long long int i=0,j=0;
    while(j<N){
        //calculation
        if(A[j] < 0){
            l.push_back(A[j]);
        }
        //make the window 
        if((j-i)+1 < K){
            j++;
        }
        else if((j-i)+1 == K){
            //ans<-calculation
            //if list is empty means this window has no negative
            if(l.size() == 0)   ans.push_back(0);
            else{
                //ans will be the first integer present at the list
                ans.push_back(l.front());
            }
            //slide the window    
            i++;
            j++;
            if(A[i-1]<0){
                l.pop_front();
            }
        }        
    }
    return ans;                                                    
 }
int main()
{
    return 0;
}

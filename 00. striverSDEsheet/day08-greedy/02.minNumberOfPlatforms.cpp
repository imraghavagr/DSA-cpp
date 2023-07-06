//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
#include<iostream>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
        sort(arr,  arr+n);
        sort(dep, dep+n);
    
        int i = 1; // to keep track of arriving train// first train has already arrived
        int j = 0; //to keep track of the departing train
        
        int maxOccupiedPlatforms  = 1;
        int currOccupiedPlatforms = 1;
        
        while(i<n){
            //if arrival time of a train is less than the train to be departed
            if(arr[i]<=dep[j]){
                //make arrival and increase platform count
                currOccupiedPlatforms++;
                maxOccupiedPlatforms = max(maxOccupiedPlatforms, currOccupiedPlatforms);
                i++;
            }
            //if currently a train is to departed, we will depart it first
            else{
                currOccupiedPlatforms--;
                j++;
            }
        }
        return maxOccupiedPlatforms;
}
int main()
{
    return 0;
}
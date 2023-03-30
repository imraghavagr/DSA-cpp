//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include<iostream>
using namespace std;
bool static compare(Item a, Item b){
    double r1 = a.value/(double)a.weight;
    double r2 = b.value/(double)b.weight;
    return r1>r2;
}
//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr+n, compare);
    double ans = 0;
    int remainingCapacity = W;
    int i = 0;
    while(i<n && remainingCapacity > 0){
        if(arr[i].weight <= remainingCapacity){
            ans += arr[i].value;
            remainingCapacity -= arr[i].weight;
        }
        else{
            double ratio = arr[i].value/(double)arr[i].weight;
            ans += remainingCapacity*ratio;
            remainingCapacity = 0;
        }
        
        i++;
    }
    return ans;
}
int main()
{
    return 0;
}
#include<iostream>
using namespace std;
void segregate0and1(int arr[], int n) {
    int i = 0, left = 0; 
    while(i<n){
        if(arr[i] == 0){
            //send 0's to the left 
            swap(arr[i], arr[left]);
            left++;
        }
        i++;
    }
}
int main()
{
    return 0;
}
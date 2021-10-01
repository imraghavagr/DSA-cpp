#include<iostream>
#include<algorithm>
using namespace std;
/*
given: 1 2 3 4 5
o/p = 5 4 3 2 1
Basic approach would to use an extra array and fill it while reading the elements from end of the original array
Better Approach:
1 2 3 4 5
Swap the elements eg. 1 with 5, 2 with 4, 3 with 3

  10 20 30 40 50 60
i= 0  1  2  3  4  5
n = 6
swap a[i] from i = 0 to n/2 with a([n-i-1]
*/
void reverseArray(int *a, int n){

    for(int i =0; i<n/2; i++){
        swap(a[i], a[n-i-1]);
    }

}
int main(){
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(int);
    cout<<"original array: "<<endl;
    for(int i =0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Reversed array:"<<endl;
    reverseArray(a,n);
    for(int i =0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
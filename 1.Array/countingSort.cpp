#include<iostream>
#include<vector>
#include<climits>
using namespace std;
/* O(range + N)
When the given numbers are in some range, but not necessary that all numbers in that range are present.
 a = [5 8 3 1 1 2 6]
 freq =[0 2 1 1 0 1 1 0 1]
        0 1 2 3 4 5 6 7 8
*/
void countingSort(vector<int> &v){
    //finding out the largest element
    int l = INT_MIN;
    for(int x : v){
        l = max(l,x);
    }
    //first lets make a frequency map kind of vector
    // for storing frequency of numbers 0 to l, we need vector of size l+1;
    vector<int> freq(l+1,0);
    for(int i = 0; i<v.size(); i++){
        int num = v[i];
        freq[num] = freq[num] + 1;
    }

    //now we will change values in v
    int j = 0; // j will keep track of original vector
    for(int i = 0; i<freq.size(); i++){
        while(freq[i] > 0){
            v[j++] = i;
            freq[i]--;
        }
    }

}

int main(){

    vector<int> v{5,8,3,1,1,2,6};
    countingSort(v);
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
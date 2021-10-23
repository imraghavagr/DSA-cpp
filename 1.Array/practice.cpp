#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
5 4 3 2 1

1 4 3 2 5 [swapped the min in unsorted array with elem at i = 0]
1 2 3 4 5 [ swapped the min in unsorted array with elem at i = 1]
1 2 3 4 5


*/
void insertionSort(vector<int> &nums)
{
   int minidx;
   int n = nums.size();
   for(int i = 0; i<n-1; i++){
       minidx = i;
       for(int j = i; j<n; j++){
           if(nums[minidx]>nums[j]){
               minidx = j;
           }
       }
       swap(nums[minidx],nums[i]);
   }
}/*
5 4 3 2 1
4 5 3 2 1
4 3 5 2 1
4 3 2 5 1
4 3 2 1 5

4 3 2 1 5 j = 1 to 
3 4 2 1 5
3 2 4 1 5
3 2 1 4 5 j <=n-1-i or j<n-i

*/
void bubbleSort(vector<int> &nums){
    //n-1 passes to sort n elements
    int n = nums.size();
    for(int i =0; i<n-1; i++){
        //in each pass we compare the adjacent elements
        for(int j = 1; j<n-i; j++){
            if(nums[j-1]>nums[j]){
                swap(nums[j-1],nums[j]);
            }
        }
    }
}
int missingNumber(vector<int> &nums){
    int i = 0;
    while(i<nums.size()){
        int correctIdx = nums[i];
        if(i != correctIdx && nums[i] < nums.size()){
            swap(nums[i],nums[correctIdx]);
        }
        else{
            i++;
        }
    }
    for(int i =0; i<nums.size(); i++){
        if(nums[i] != i ){
            return i;
        }
    }
    return nums.size();
}
int main()
{

    vector<int> nums{0,1};

    //insertionSort(nums);
    int ans = missingNumber(nums);
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
    cout<<ans<<endl;
   

    return 0;
}
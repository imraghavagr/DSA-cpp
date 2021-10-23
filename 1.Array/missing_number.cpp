//https://leetcode.com/problems/missing-number/
//@amazon
// cyclic sort ques
//Now since the numbers are in range 0 to n,
// the numbers (in sorted array will be at number == index )
//eg-
//N=3 0 1 2 3
//idx 0 1 2 3 (means number and idx are same)
#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int i = 0;
    while (i < nums.size())
    {
        int correct_idx = nums[i];
        if (nums[i] < nums.size() && nums[i] != nums[correct_idx])
        {
            swap(nums[i], nums[correct_idx]);

        }
        else
        {
            i++;
        }
    }
    for(int i = 0;i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    //now the ans will be the first number that is not at its correct idx
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
}
int main()
{

    vector<int> v{3,0,1};
    int ans = missingNumber(v);
    //missingNumber(v);
    cout << ans<< endl;
    return 0;
}
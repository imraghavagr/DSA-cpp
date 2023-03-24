#include<iostream>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
    int num1, num2;
    int count1 = 0, count2 = 0;
    for(int i : nums){
        if(i == num1)   count1++;
        else if(i == num2)  count2++;
        else if(count1 == 0){
            num1 = i;
            count1 = 1;
        }
        else if(count2 == 0){
            num2 = i;
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    int majority = nums.size()/3;
    vector<int> ans;
    count1 = 0;
    count2 = 0;
    for(int i : nums){
        if(i == num1)   count1++;
        if(i == num2)   count2++;
    }
    if(count1 > majority)    ans.push_back(num1);
    if(count2 > majority)  ans.push_back(num2);
    
    return ans;
}
int main()
{
    return 0;
}
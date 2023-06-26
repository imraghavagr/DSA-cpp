//https://leetcode.com/problems/sliding-window-maximum/
#include<iostream>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    list<int> l;
    int i = 0;
    int j = 0;
    while(j<nums.size()){
        //some calculation for j
        //we only need the elements which are greater than the curr element in the queue
        while(l.size()>0 && l.back() < nums[j])    l.pop_back();
        l.push_back(nums[j]);

        if(j-i+1 < k)   j++;

        else{
            //window is formed 
            ans.push_back(l.front());
            //slide the window
            i++;
            j++;
            //remove calc for the element left out while sliding the window 
            if(l.front() == nums[i-1])  l.pop_front();
        }
    }
    return ans;
}
int main()
{
    return 0;
}
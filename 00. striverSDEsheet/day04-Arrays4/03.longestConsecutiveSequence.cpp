#include<iostream>
using namespace std;
//using set ds - O(nlogx) time, O(x) space .. x size of set, which will be equal to n in the worst case when all elements are distinct
int longestConsecutive1(vector<int>& nums) {
    set<int> st(nums.begin(), nums.end());
    int prev = INT_MIN;
    int longest = 0;
    int cnt = 0;
    for(auto it : st){
        if(it == prev+1)    cnt++;
        else{
            cnt = 1;
        }
        prev = it;
        longest = max(longest, cnt);
    }
    return longest;
}
//Sorting - O(nlogn)time O(1)space
int longestConsecutive2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int lastSmaller = INT_MIN;
    int cnt = 0, longest = 0;
    for(int num : nums){
        if(lastSmaller+1 == num){
            cnt++;
            lastSmaller = num;
        }
        else if(lastSmaller != num){
            cnt = 1;
            lastSmaller = num;
        }
        longest = max(longest, cnt);
    }
    return longest;
}
//O(3n) + O(n) space 
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int cnt, ans = 0;
    //search for the increasing sequence only from the starting element of a 
    //possible sequence
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            //this means it can be a starting element 
            //now we can keep on searching for it+1 
            int x = it+1;
            cnt = 1; 
            while(st.find(x) != st.end()){
                cnt++;
                x = x + 1;
            }
            ans = max(cnt, ans);
        }
    }
    return ans;
}
int main()
{
    return 0;
}
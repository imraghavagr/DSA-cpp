//https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include<iostream>
using namespace std;
void solve(vector<int> ip, vector<int> &ans, int sum){
    if(ip.size() == 0){
        ans.push_back(sum);
        return;
    }    
    //pick and not pick 
    int x = ip[0];
    ip.erase(ip.begin()+0);
    solve(ip, ans, sum+x);
    solve(ip, ans, sum);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    int sum = 0;
    vector<int> ans;
    solve(arr, ans, sum);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{

    return 0;
}
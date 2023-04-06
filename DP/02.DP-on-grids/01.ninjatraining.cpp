//https://practice.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training
#include<iostream>
using namespace std;
//memoized code
int solve(int day, int prevTask, vector<vector<int>> &points,
vector<vector<int>> &dp){
    if(day == 0){
        int maxMerit = 0;
        for(int i = 0; i<=2; i++){
            if(i != prevTask){
                maxMerit = max(maxMerit, points[day][i]);
            }
        }
        return maxMerit;
    }
    if(dp[day][prevTask] != -1) return dp[day][prevTask];
    //else we will try to perform all the task except the prev task
    int maxMerit = 0;
    for(int i = 0; i<=2; i++){
        if(i!=prevTask){
            int merit = points[day][i] + solve(day-1, i, points, dp);
            maxMerit = max(maxMerit, merit);
        }
    }
    return dp[day][prevTask] = maxMerit;
}
int maximumPoints(vector<vector<int>>& points, int n) {
    // Code here
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return solve(n-1, 3, points, dp);
}
int main()
{
    return 0;
}
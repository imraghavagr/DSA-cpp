//https://practice.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training
#include<iostream>
using namespace std;
//memoized code
int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    //base case
    if(day == 0){
        int maxMerit = 0;
        for(int activity = 0; activity <= 2; activity++){
            if(activity != last){
                maxMerit = max(maxMerit, points[day][activity]);
            }
        }
        return maxMerit;
    }
    if(dp[day][last] != -1) return dp[day][last];
    //for the current day, we will try to do all the activites except the last activity 
    int maxMerit = 0;
    for(int activity = 0; activity <= 2; activity++){
        if(activity != last){
            int merit = points[day][activity] + solve(day-1, activity, points, dp);
            maxMerit = max(maxMerit, merit);
        }
    }
    return dp[day][last] = maxMerit;
}
//tabular approach 
int solve(vector<vector<int>> &points, int n){

    vector<vector<int>> dp(n, vector<int>(4, -1));
    //initialization for day0 and for each activity 
    for(int pastActivity = 0; pastActivity <4; pastActivity++){
        int maxMerit = 0;
        for(int activity = 0; activity <= 2; activity++){
            if(activity != pastActivity){
                maxMerit = max(maxMerit, points[0][activity]);
            }
        }
        dp[0][pastActivity] = maxMerit;
    }
    for(int day = 1; day<n; day++){
        for(int pastActivity = 0; pastActivity<4; pastActivity++){
            int maxMerit = 0;
            for(int activity = 0; activity <= 2; activity++){
                if(activity != pastActivity){
                    int merit = points[day][activity] + dp[day-1][activity];
                    maxMerit = max(maxMerit, merit);
                }
            }
            dp[day][pastActivity] = maxMerit;       
        }
    }
    return dp[n-1][3];
}
//tabular approach - space optimized - optimal method
int solve(vector<vector<int>> &points, int n){

    vector<int> dp(4, -1);
    //initialization for day0 and for each activity 
    for(int pastActivity = 0; pastActivity <4; pastActivity++){
        int maxMerit = 0;
        for(int activity = 0; activity <= 2; activity++){
            if(activity != pastActivity){
                maxMerit = max(maxMerit, points[0][activity]);
            }
        }
        dp[pastActivity] = maxMerit;
    }
    for(int day = 1; day<n; day++){
        vector<int> temp(4, -1);
        for(int pastActivity = 0; pastActivity<4; pastActivity++){
            int maxMerit = 0;
            for(int activity = 0; activity <= 2; activity++){
                if(activity != pastActivity){
                    int merit = points[day][activity] + dp[activity];
                    maxMerit = max(maxMerit, merit);
                }
            }
            temp[pastActivity] = maxMerit;
        }
        dp = temp;
    }
    return dp[3];
}
int main()
{
    return 0;
}
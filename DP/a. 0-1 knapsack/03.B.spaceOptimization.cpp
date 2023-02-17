//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
//see striver's DP 19. 0/1 Knapsack  video ending for explaination of space optimization - 
//https://www.youtube.com/watch?v=GqOmJHQZivw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=20&t=126s&ab_channel=takeUforward
#include<iostream>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) 
{
    //space optimized approach 
    vector<int> dp(W+1, 0);
    for(int i = 1; i<=n; i++){
        for(int j = W; j>=0; j--){
            if(wt[i-1] <= j){
                dp[j] = max(val[i-1] + dp[j-wt[i-1]], dp[j]);
            }
            // else{
            //     dp[j] = dp[j];
            // }
        }
    }
    return dp[W];
}

int main()
{   
    int val[] = {10,20,30};
    int wt[] =  {1,1,1};
    int w = 2; //knapsack capacity
    int n = sizeof(val)/sizeof(int);
    cout<<knapSack(w,wt,val,n)<<endl;
    return 0;
}
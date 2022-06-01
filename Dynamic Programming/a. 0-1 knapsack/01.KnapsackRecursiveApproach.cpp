/*
There are three approaches:
    1.Recursive Code
    2.Recursive Code + Matrix (memoization) = DP[Top-Down Approach]
    3.Tabular Approach (DP- Bottom Up Approach)
*/
//recursive approach
#include<iostream>
using namespace std;
int knapsack(int*wt, int*val, int n, int w){
    //base case
    if(n==0 || w == 0){
        return 0;
    }

    //rec case
    if(wt[n-1] <= w){
        //if wt of item <= w (bag capacity) then two choices- either select the item or do not select it
        int choice1 = val[n-1] + knapsack(wt,val,n-1,w-wt[n-1]);
        int choice2 = knapsack(wt,val,n-1,w);
        return max(choice1,choice2);
    }
    else{
        //wt of the item exceeds w, then do not pick the item
        return knapsack(wt,val,n-1,w);
    }
}
int main()
{   
    int val[] = {10,20,30};
    int wt[] =  {1,1,1};
    int w = 2; //knapsack capacity
    int n = sizeof(val)/sizeof(int);
    cout<<knapsack(wt,val,n,w)<<endl;
    return 0;
}
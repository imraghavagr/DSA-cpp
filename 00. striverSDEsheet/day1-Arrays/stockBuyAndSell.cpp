#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int maxProfit1(vector<int>& v) { // -> O(n2) approach
    int maxProfit = 0;
    for(int i = 0; i<v.size(); i++){
        //buy at ith index or i+1 day
        int profit = 0;
        for(int j = i+1; j<v.size(); j++){
            //we will sell at all days where stock price is greater than the
            //stock price at ith index 
            if(v[j]>v[i]){
                //sell the stock, calculate the profit
                profit = v[j] - v[i];
            }
            maxProfit = max(profit,maxProfit);
        }
    }
    return maxProfit;
}
//Optimal - O(n) approach
int maxProfit2(vector<int>& v) {
    int min = INT_MAX;
    int maxProfit = 0;
    for(int i = 0; i<v.size(); i++){
        if(min > v[i]){
            min = v[i];
        }
        if (v[i]>min){
            //sell the stock and calculate the profit
            int profit = v[i] - min;
            maxProfit = max(maxProfit,profit);
        }
    }
    return maxProfit;
}
int main()
{
    vector<int> v = {7,1,5,3,6,4};
    cout<<maxProfit2(v)<<endl;
    return 0;
}

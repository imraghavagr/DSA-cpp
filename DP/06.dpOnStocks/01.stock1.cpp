//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include<iostream>
using namespace std;

//O(n) time, O(1) space 
int maxProfit(vector<int>& prices) {
    int maximumProfit = 0;
    int minPrice = prices[0];
    for(int i = 1; i<prices.size(); i++){
        int profit = prices[i] - minPrice;
        maximumProfit = max(maximumProfit, profit);
        minPrice = min(minPrice, prices[i]);
    }
    return maximumProfit;
}
int main()
{
    return 0;
}
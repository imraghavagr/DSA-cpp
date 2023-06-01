#include<iostream>
using namespace std;
//just include transaction fee
//transaction fee will be applicable after 1 buy and sell 
int maxProfit(vector<int>& prices, int fee) {
    
    int n = prices.size();        
    vector<int> ahead(2, 0), curr(2, 0);
    for(int idx = n-1; idx>=0; idx--){
        for(int buy = 0; buy<=1; buy++){
            int profit = 0;
            if(buy){
                profit = max(-prices[idx] + ahead[0], ahead[1]);
            }
            else{
                profit = max(prices[idx]-fee + ahead[1], ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}
int main()
{
    return 0;
}
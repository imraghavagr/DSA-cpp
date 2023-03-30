//https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
#include<iostream>
using namespace std;
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> currency = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int i = 0;
    int numCoins = 0;
    while(i<currency.size() && amount>0){
        if(currency[i] <= amount){
            numCoins += amount/currency[i];
            amount = amount%currency[i];
        }
        i++;
    }
    return numCoins;
}
int main()
{
    return 0;
}
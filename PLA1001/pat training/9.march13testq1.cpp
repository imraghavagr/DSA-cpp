#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//102, 5 -> 
int main()
{   
    vector<int> itemNum = {101, 102, 103, 108};
    vector<int> itemPrice = {42, 50, 500, 40};
    vector<int> itemStocks = {10,20,15,16};

    int numItems, quantitiyItem;
    cin>>numItems>>quantitiyItem;

    //item num -> {itemStock , price}
    unordered_map<int,pair<int,int>> mp;

    for(int i = 0; i<itemNum.size(); i++){
        pair<int,int> p; 
        p.first = itemStocks[i];
        p.second = itemPrice[i];
        mp[itemNum[i]] = p;
    }


    if(mp[numItems].first >= quantitiyItem){
        float price = quantitiyItem*mp[numItems].second;
        cout<<"Total price :"<<price<<endl;
        //update the stock quantity 
        mp[numItems].first = mp[numItems].first - quantitiyItem;
    }
    else{
        cout<<"NO STOCK and quantity left"<<endl;
    }
    
    return 0;
}
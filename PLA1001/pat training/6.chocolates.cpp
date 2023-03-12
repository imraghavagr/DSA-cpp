#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int moneyReturned;
    cin>>moneyReturned;
    vector<int> chocolateCosts = {3,7};
    int moneySpent = 100-moneyReturned;
    int cntOfThree = 0;
    while(moneySpent % 7 != 0 && moneySpent>0){
        cntOfThree++;
        moneySpent -= 3;
    }

    if(moneySpent == 0 || moneySpent % 7 == 0){
        cout<<"Three Count = "<<cntOfThree<<endl;
        cout<<"Seven Count = "<<moneySpent/7<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }   

    return 0;
}
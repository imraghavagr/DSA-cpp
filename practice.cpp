#include<iostream>
#include<vector>
#include<climits>
using namespace std;
bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size()  != groupSize*groupSize){
        return false;
    }
    int largest = INT_MIN;
    for(int i = 0; i<hand.size(); i++){
        largest = max(largest,hand[i]);
    }
    cout<<largest<<endl;
    vector<int> freq(largest+1,0);
    cout<<"Fine "<<endl;
    for(int i = 0; i<hand.size(); i++){
        freq[hand[i]]++;
    }
    cout<<"Everything fine till here"<<endl;
    
    int groupsFormed = 0;
    int cardsInCurrGroup = 0;
    int lastAvailableCard = INT_MAX;
    for(int i = 0; i<freq.size(); i++){
        if(freq[i]>0){
            freq[i]--;
            if(freq[i] > 0){
                lastAvailableCard = min(lastAvailableCard,i);
            }
            cardsInCurrGroup++;
            if(cardsInCurrGroup == groupSize){
                groupsFormed++;
                cardsInCurrGroup = 0;
                if(freq[lastAvailableCard] > 0)
                    i = lastAvailableCard-1;
            }
        }
        
    }
    return groupsFormed == groupSize;
}
int main()
{   
    vector<int> v{1,2,3,6,2,3,4,7,8};
    int grpSize = 3;
    cout<<isNStraightHand(v,grpSize)<<endl;
    return 0;
}
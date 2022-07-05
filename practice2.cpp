#include<bits/stdc++.h>
using namespace std;
bool bs(int* arr, int n, int key){
    if(key<arr[0] || key > arr[n-1])return false;
    int s = 0;
    int e = n-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(key==arr[mid]){
            return true;
        }
        else if(key>arr[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }

    }
    return false;
}
int main(){

    int totalSeats,soldTickets,likeSeats;
    cin>>totalSeats>>soldTickets>>likeSeats;
    int filledSeats[soldTickets];
    for(int i = 0; i<soldTickets;i++){
        cin>>filledSeats[i];
    }
    char likeArr[likeSeats];
    // for(int i = 0; i<likeSeats; i++){
    //     int no;
    //     cin>>no;
    //     //find if this no is present in filledSeats array or not
    //     auto it = find(filledSeats,filledSeats+soldTickets,no);
    //     int idx = it-filledSeats;
    //     if(idx == soldTickets){
    //         //means this seat is not filled
    //         likeArr[i] = 'Y';
    //     }
    //     else{
    //         likeArr[i] = 'N';
    //     }

    // }
    //another implementation 
    //sort the filledSeats array 
    sort(filledSeats,filledSeats+soldTickets);
    
    for(int i =0; i<likeSeats; i++){
        int no;
        cin>>no;
        //search if 'no.' seat is present in filledSeats array or not using binary search
        if(bs(filledSeats,soldTickets,no)){
            //no is present .. means seat is filled 
            likeArr[i] = 'N';
        }
        else{
            likeArr[i] = 'Y';
        }
    }
    
    for(int i =0; i<likeSeats; i++){
        cout<<likeArr[i]<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
//Find Displacement: Given a long route containing N,S,E,W directions, find the shortest path to reach the location.
//sample ip = SNNNEWE
//sample op = NNE
/*
    think about cartesian plane
        N
    W       E
        S
    if a person moves in North, we will add 1 in y dirn, it he moves south, we will add -1 in y dirn.
    similarly +1 in x for East  and -1 in x for west

*/
int main(){
    char ch; //we willl read the given array chars one by one.
    ch = cin.get();
    int x = 0, y =0; // initiall position is origin
    while(ch != '\n'){
        if(ch == 'N' or ch == 'n')  y++;
        else if(ch == 'S' or ch == 's') y--;
        else if(ch == 'W' or ch == 'w') x--;
        else    x++;
        ch = cin.get();
    }
    cout<<x<<y<<endl;
    if(x>=0 and y>=0){
        //first quad
        while(x>0){
            x--;
            cout<<"E";
        }
        while(y>0){
            y--;
            cout<<"N";
        }
    }
    else if(x<=0 and y>=0){
        //second quadr
        while(x<0){
            x++;
            cout<<"W";
        }
        while(y>0){
            y--;
            cout<<"N";
        }
    }
    else if(x<=0 and y<=0){
        //third quadr
        while(x<0){
            x++;
            cout<<"W";
        }
        while(y<0){
            y++;
            cout<<"S";
        }
    }
    else if(x>=0 and y<=0){
        //fourth quadr
        while(x>0){
            x--;
            cout<<"E";
        }
        while(y<0){
            y++;
            cout<<"S";
        }
    }




    return 0;
}